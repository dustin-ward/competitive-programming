use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let a: f64 = line.trim().parse::<f64>().unwrap();

    println!("{}", a.sqrt()*4.0)
}
