use std::io;
use std::cmp;
use std::convert::TryInto;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let [n,k]: [i32; 2] = line
        .split_whitespace()
        .map(|s| s.parse::<i32>())
        .collect::<Result<Vec<_>,_>>()
        .unwrap()
        .try_into()
        .unwrap();

    let mut arr = Vec::new();
    for _ in 0..n {
        line = String::new();
        io::stdin().read_line(&mut line);
        let [a,b]: [i32; 2] = line
            .split_whitespace()
            .map(|s| s.parse::<i32>())
            .collect::<Result<Vec<_>,_>>()
            .unwrap()
            .try_into()
            .unwrap();

        arr.push((cmp::max(a-k,0),-1));
        arr.push((b,1));
    }
    arr.sort();

    let mut ans = 0;
    let mut cur = 0;
    for (_,v) in arr {
        cur -= v;
        ans = cmp::max(ans, cur);
    }
    println!("{}", ans);
}
