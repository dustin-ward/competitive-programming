use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let n = line.trim().parse::<i32>().unwrap();

    let mut ans = 0;
    for _ in 0..n {
        line = String::new();
        io::stdin().read_line(&mut line);

        let temp = line.trim().to_lowercase();
        if temp.contains("pink") || temp.contains("rose") {
            ans+=1;
        }
    }

    if ans > 0 {
        println!("{}", ans);
    } else {
        println!("I must watch Star Wars with my daughter");
    }
}
