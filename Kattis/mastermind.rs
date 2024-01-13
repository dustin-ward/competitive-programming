use std::cmp::min;
use std::collections::HashMap;
use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let p = line.split_whitespace().collect::<Vec<&str>>();

    let n: i32 = p[0].parse().unwrap();
    let orig = p[1].chars();
    let code = p[2].chars();

    let mut r: i32 = 0;
    let mut s: i32 = 0;

    let mut rem_a = HashMap::new();
    let mut rem_b = HashMap::new();
    for (a, b) in orig.zip(code) {
        if a == b {
            r += 1;
        } else {
            rem_a.entry(a).and_modify(|a| *a += 1).or_insert(1);
            rem_b.entry(b).and_modify(|b| *b += 1).or_insert(1);
        }
    }

    for (ch, v) in &rem_a {
        match rem_b.get(&ch) {
            Some(v2) => {
                s += min(v, v2);
            }
            None => {}
        }
    }

    println!("{} {}", r, s);
}
