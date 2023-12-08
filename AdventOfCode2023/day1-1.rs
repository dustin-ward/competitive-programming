use std::io;

fn main() {
    let mut ans = 0;
    for line in io::stdin().lines() {
        let mut first: i32 = -1;
        let mut last: i32 = -1;
        for ch in line.unwrap().chars() {
            if ch.is_digit(10) {
                if first == -1 {
                    first = ch.to_digit(10).unwrap() as i32;
                }
                last = ch.to_digit(10).unwrap() as i32;
            }
        }
        ans += (first*10)+last;
    }
    println!("Ans: {ans}")
}
