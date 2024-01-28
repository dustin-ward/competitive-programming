use std::collections::HashMap;
use std::io;

fn main() {
    let mut first = true;
    'testcase: loop {
        let mut line = String::new();
        match io::stdin().read_line(&mut line) {
            Ok(0) => {
                break;
            }
            _ => {}
        }
        let n: u32 = line.trim().parse().unwrap();

        let mut map: HashMap<String, u32> = HashMap::new();
        loop {
            line = String::new();
            io::stdin().read_line(&mut line);
            if line == "\n" {
                continue;
            } else if line == String::from("EndOfText\n") {
                break;
            }

            let words: Vec<String> = line
                .chars()
                .map(|ch| match ch {
                    ch if ch.is_alphabetic() => ch,
                    _ => ' ',
                })
                .collect::<String>()
                .split_whitespace()
                .map(|w| w.to_lowercase())
                .collect();

            for w in words {
                map.entry(w).and_modify(|x| *x += 1).or_insert(1);
            }
        }

        let mut ans: Vec<String> = map
            .into_iter()
            .filter(|(k, v)| *v == n)
            .map(|(k, v)| k)
            .collect();

        if !first {
            println!("");
        }
        first = false;
        if ans.len() == 0 {
            println!("There is no such word.");
        } else {
            ans.sort();
            for w in ans {
                println!("{}", w);
            }
        }
    }
}
