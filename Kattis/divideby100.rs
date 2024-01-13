use std::io;

fn main() {
    let mut n = String::new();
    let mut m = String::new();
    io::stdin().read_line(&mut n);
    io::stdin().read_line(&mut m);
    n = n.trim().to_string();
    m = m.trim().to_string();

    let mut dif = m.len() as i32 - n.len() as i32;
    if dif > 0 {
        n.insert_str(0, "0".repeat(dif as usize).as_str());
    }

    dif = n.len() as i32 - m.len() as i32;
    n.insert((dif + 1) as usize, '.');

    n = n.trim_right_matches('0').to_string();
    n = n.trim_right_matches('.').to_string();

    println!("{}", n);
}
