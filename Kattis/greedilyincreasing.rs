use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let n: i32 = line.trim().parse().unwrap();
    line = String::new();

    io::stdin().read_line(&mut line);
    let mut arr = line
        .split_whitespace()
        .map(|x| x.parse::<i32>())
        .collect::<Result<Vec<i32>, _>>()
        .unwrap();

    let mut ans: Vec<i32> = Vec::new();
    arr.iter().for_each(|x| {
        if ans.len() == 0 || x > &ans[ans.len() - 1] {
            ans.push(*x)
        }
    });

    println!("{}", ans.len());
    ans.iter().for_each(|x| print!("{} ", x));
    print!("\n");
}
