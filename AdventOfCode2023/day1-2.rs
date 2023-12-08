use std::io;

fn main() {
    let mut ans = 0;
    for line in io::stdin().lines() {
        let mut string = line.unwrap();
        string = string.replace("one", "o1e");
        string = string.replace("two", "t2o");
        string = string.replace("three", "th3ee");
        string = string.replace("four", "f4ur");
        string = string.replace("five", "fi5e");
        string = string.replace("six", "s6x");
        string = string.replace("seven", "se7en");
        string = string.replace("eight", "ei8ht");
        string = string.replace("nine", "ni9e");

        let mut first: i32 = -1;
        let mut last: i32 = -1;
        for ch in string.chars() {
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
