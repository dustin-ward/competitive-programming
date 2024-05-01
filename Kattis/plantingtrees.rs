use std::io;
use std::cmp;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let n = line.trim().parse::<i32>().unwrap();

    line = String::new();
    io::stdin().read_line(&mut line);
    let mut arr = Vec::new();
    for ch in line.trim().split(" ") {
        arr.push(ch.parse::<i32>().unwrap());   
    }

    arr.sort();
    let mut ans = 0;
    for (i, v) in arr.iter().rev().enumerate() {
        ans = cmp::max(ans, v+(i as i32));       
    }
    println!("{}", ans+2);
}
