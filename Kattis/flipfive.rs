use std::collections::VecDeque;
use std::io;

const FLIP: &[u32] = &[11, 23, 38, 89, 186, 308, 200, 464, 416];

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let p = line.trim().parse::<u32>().unwrap();

    for _ in 0..p {
        let mut init_state = 0;

        for i in 0..3 {
            line = String::new();
            io::stdin().read_line(&mut line);

            for (j, ch) in line.trim().chars().enumerate() {
                if ch == '*' {
                    init_state |= 1 << (i * 3 + j);
                }
            }
        }

        let mut dp = [-1; (1 << 9)];
        let mut q = VecDeque::from([init_state]);
        dp[init_state as usize] = 0;
        while !q.is_empty() {
            let cur_state = q.pop_front().unwrap();
            for i in 0..9 {
                let next_state = cur_state ^ FLIP[i];
                if dp[next_state as usize] == -1 {
                    q.push_back(next_state);
                    dp[next_state as usize] = dp[cur_state as usize] + 1;
                }
            }
        }

        println!("{}", dp[0]);
    }
}
