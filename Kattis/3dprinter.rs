use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let n = line.trim().parse::<i32>().unwrap();

    let mut printers = 1;
    let mut days = 0;
    while printers < n {
        days += 1;
        printers *= 2;
    }
    println!("{}", days + 1);
}
