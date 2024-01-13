use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);

    let mut ans = String::new();
    line.split('-').for_each(|a| ans.push_str(&a[0..1]));

    println!("{}", ans);
}
