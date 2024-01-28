use std::cmp;
use std::convert::TryInto;
use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let t: i32 = line.trim().parse::<i32>().unwrap();

    for _ in 0..t {
        line = String::new();
        io::stdin().read_line(&mut line);
        let [l, n]: [i32; 2] = line
            .split_whitespace()
            .map(|x| x.parse::<i32>())
            .collect::<Result<Vec<i32>, _>>()
            .unwrap()
            .try_into()
            .unwrap_or_default();

        let mut arr: Vec<i32> = Vec::new();
        while arr.len() as i32 != n {
            line = String::new();
            io::stdin().read_line(&mut line);
            let temp = line
                .split_whitespace()
                .map(|x| x.parse::<i32>())
                .collect::<Result<Vec<i32>, _>>()
                .unwrap();

            arr.extend(temp);
        }

        let mut earliest = 0;
        let mut latest = 0;
        for i in 0..n as usize {
            let lo = cmp::min(arr[i], l - arr[i]);
            let hi = cmp::max(arr[i], l - arr[i]);
            earliest = cmp::max(earliest, lo);
            latest = cmp::max(latest, hi);
        }

        println!("{} {}", earliest, latest);
    }
}
