use std::collections::BinaryHeap;
use std::convert::TryInto;
use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let [n, t]: [i32; 2] = line
        .split_whitespace()
        .map(|s| s.parse::<i32>())
        .collect::<Result<Vec<_>, _>>()
        .unwrap()
        .try_into()
        .unwrap();

    let mut customers = Vec::new();
    for _ in 0..n {
        line = String::new();
        io::stdin().read_line(&mut line);
        let [c, l]: [i32; 2] = line
            .split_whitespace()
            .map(|s| s.parse::<i32>())
            .collect::<Result<Vec<_>, _>>()
            .unwrap()
            .try_into()
            .unwrap();

        customers.push((l, c));
    }

    customers.sort_by(|a, b| b.cmp(a));

    let mut pq = BinaryHeap::new();

    let mut ans = 0;
    let mut i: usize = 0;
    for cur_time in (0..=t).rev() {
        while i < n as usize && customers[i].0 == cur_time {
            pq.push(customers[i].1);
            i += 1;
        }

        if !pq.is_empty() {
            let top = pq.pop().unwrap();
            ans += top;
        }
    }

    println!("{}", ans);
}
