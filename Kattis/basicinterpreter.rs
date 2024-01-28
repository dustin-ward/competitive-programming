use std::collections::HashMap;
use std::io;
use std::num::Wrapping;
use std::str::FromStr;

#[derive(Debug, Clone)]
enum Value {
    Numeric(i32),
    Ident(String),
    String(String),
}

#[derive(Debug, Clone)]
enum ExpressionType {
    Arithmetic,
    Condition,
}

#[derive(Debug, Clone)]
struct Expression {
    expr_type: ExpressionType,
    lhs: Value,
    op: Option<String>,
    rhs: Option<Value>,
}

impl Expression {
    fn eval(&self, memory: &HashMap<String, i32>) -> Value {
        if let None = self.op {
            return self.lhs.clone();
        }
        let lhs_val = match self.lhs.clone() {
            Value::Numeric(val) => val,
            Value::Ident(ident) => *memory.get(&ident).unwrap_or(&0),
            _ => todo!(),
        };
        let rhs_val = match self.rhs.clone().unwrap() {
            Value::Numeric(val) => val,
            Value::Ident(ident) => *memory.get(&ident).unwrap_or(&0),
            _ => todo!(),
        };

        match self.expr_type {
            ExpressionType::Arithmetic => match self.op.clone().unwrap().as_str() {
                "+" => Value::Numeric((Wrapping(lhs_val) + Wrapping(rhs_val)).0),
                "-" => Value::Numeric((Wrapping(lhs_val) - Wrapping(rhs_val)).0),
                "*" => Value::Numeric((Wrapping(lhs_val) * Wrapping(rhs_val)).0),
                "/" => Value::Numeric((Wrapping(lhs_val) / Wrapping(rhs_val)).0),
                _ => unreachable!(),
            },
            ExpressionType::Condition => match self.op.clone().unwrap().as_str() {
                "=" => Value::Numeric((lhs_val == rhs_val) as i32),
                ">" => Value::Numeric((lhs_val > rhs_val) as i32),
                "<" => Value::Numeric((lhs_val < rhs_val) as i32),
                "<>" => Value::Numeric((lhs_val != rhs_val) as i32),
                "<=" => Value::Numeric((lhs_val <= rhs_val) as i32),
                ">=" => Value::Numeric((lhs_val >= rhs_val) as i32),
                _ => unreachable!(),
            },
        }
    }
}

fn parse_expr(tokens: &mut [String], t: ExpressionType) -> Expression {
    match t {
        ExpressionType::Arithmetic => Expression {
            expr_type: ExpressionType::Arithmetic,
            lhs: match i32::from_str(tokens[0].as_str()) {
                Ok(i) => Value::Numeric(i),
                _ => Value::Ident(tokens[0].clone()),
            },
            op: (if tokens.len() > 1 {
                Some(tokens[1].clone())
            } else {
                None
            }),
            rhs: (if tokens.len() > 2 {
                Some(match i32::from_str(tokens[2].as_str()) {
                    Ok(i) => Value::Numeric(i),
                    _ => Value::Ident(tokens[2].clone()),
                })
            } else {
                None
            }),
        },
        ExpressionType::Condition => Expression {
            expr_type: ExpressionType::Condition,
            lhs: match i32::from_str(tokens[0].as_str()) {
                Ok(i) => Value::Numeric(i),
                _ => Value::Ident(tokens[0].clone()),
            },
            op: (if tokens.len() > 1 {
                Some(tokens[1].clone())
            } else {
                None
            }),
            rhs: (if tokens.len() > 2 {
                Some(match i32::from_str(tokens[2].as_str()) {
                    Ok(i) => Value::Numeric(i),
                    _ => Value::Ident(tokens[2].clone()),
                })
            } else {
                None
            }),
        },
    }
}

#[derive(Debug, Clone)]
enum Statement {
    Let { lhs: Value, rhs: Expression },
    If { cond: Expression, label: i32 },
    Print { ident: Value },
    Println { ident: Value },
}

fn main() {
    let mut memory: HashMap<String, i32> = HashMap::new();
    let mut label_lookup: HashMap<i32, usize> = HashMap::new();
    let mut program: Vec<(i32, Statement)> = Vec::new();
    let mut line = String::new();
    while let Ok(b) = io::stdin().read_line(&mut line) {
        if b == 0 {
            break;
        }

        let mut tokens: Vec<String> = line.split_whitespace().map(|s| String::from(s)).collect();
        line = String::new();
        let label: i32 = tokens[0].parse().unwrap();

        let cmd = &tokens[1];
        let cur_stmt = match cmd.as_str() {
            "LET" => {
                let lhs = match i32::from_str(tokens[2].as_str()) {
                    Ok(i) => Value::Numeric(i),
                    _ => Value::Ident(tokens[2].clone()),
                };

                assert!(tokens[3] == "=");

                let rhs = parse_expr(&mut tokens[4..], ExpressionType::Arithmetic);
                Statement::Let { lhs, rhs }
            }
            "IF" => {
                let cond = parse_expr(&mut tokens[2..5], ExpressionType::Condition);

                assert!(tokens[5] == "THEN");
                assert!(tokens[6] == "GOTO");

                let label = i32::from_str(tokens[7].as_str()).unwrap();

                Statement::If { cond, label }
            }
            "PRINT" => {
                let mut stmt: String;
                let ident = if tokens[2].starts_with("\"") {
                    stmt = tokens[2].clone();
                    for s in &tokens[3..] {
                        stmt = format!("{} {}", stmt, s.clone());
                    }
                    Value::String(stmt.trim_matches('\"').to_string())
                } else {
                    Value::Ident(tokens[2].clone())
                };
                Statement::Print { ident }
            }
            "PRINTLN" => {
                let mut stmt: String;
                let ident = if tokens[2].starts_with("\"") {
                    stmt = tokens[2].clone();
                    for s in &tokens[3..] {
                        stmt = format!("{} {}", stmt, s.clone());
                    }
                    Value::String(stmt.trim_matches('\"').to_string())
                } else {
                    Value::Ident(tokens[2].clone())
                };
                Statement::Println { ident }
            }
            _ => unreachable!(),
        };

        program.push((label, cur_stmt));
    }
    program.sort_by(|a, b| a.0.cmp(&b.0));
    for (i, (l, _)) in program.iter().enumerate() {
        label_lookup.insert(*l, i);
    }

    // Execution
    let mut pc = 0;
    while pc < program.len() {
        // println!("pc = {}", pc);
        // println!("mem = {:?}", memory);
        match &program[pc] {
            (_, Statement::Let { lhs, rhs }) => {
                let rhs_val = match rhs.eval(&memory) {
                    Value::Numeric(val) => val,
                    Value::Ident(ident_r) => *memory.get(&ident_r).unwrap_or(&0),
                    _ => unreachable!(),
                };
                if let Value::Ident(ident) = lhs.clone() {
                    memory.insert(ident, rhs_val);
                }
            }
            (_, Statement::If { cond, label }) => {
                if let Value::Numeric(val) = cond.eval(&memory) {
                    if val == 1 {
                        pc = *label_lookup.get(&label).unwrap();
                        continue;
                    }
                }
            }
            (_, Statement::Print { ident }) => {
                let txt = match ident.clone() {
                    Value::String(txt) => txt,
                    Value::Ident(ident) => (*memory.get(&ident).unwrap_or(&0)).to_string(),
                    _ => unreachable!(),
                };
                print!("{}", txt);
            }
            (_, Statement::Println { ident }) => {
                let txt = match ident.clone() {
                    Value::String(txt) => txt,
                    Value::Ident(ident) => (*memory.get(&ident).unwrap_or(&0)).to_string(),
                    _ => unreachable!(),
                };
                println!("{}", txt);
            }
        }
        pc += 1;
    }
}
