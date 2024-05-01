use std::io;

fn parse_line(line: String) -> i32 {
    let mut sum = 0;
    for ch in line.trim().split(" ") {
        sum *= 10;
        sum += ch.parse::<i32>().unwrap();
    }
    return sum;
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let t: i32 = line.trim().parse::<i32>().unwrap();

    for _ in 0..t {
        line = String::new();
        io::stdin().read_line(&mut line);
        let x = parse_line(line);

        line = String::new();
        io::stdin().read_line(&mut line);
        let y = parse_line(line);

        let mut ans = (x+y).to_string();
        ans = ans.chars()
            .flat_map(|c| [c, ' '])
            .take(ans.chars().count()*2-1)
            .collect::<String>();
        println!("{}", ans);
    }
}
