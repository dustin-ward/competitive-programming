fn main() {
    let mut line = String::new();
    let mut v: Vec<i32> = vec![0];
    while std::io::stdin().read_line(&mut line).unwrap() > 0 {
        line = line.trim().to_owned();
        if line == "" {
            v.push(0);
        }
        else {
            *v.last_mut().unwrap() += line.parse::<i32>().unwrap();
        }
    }
    v.sort();
    v.reverse();
    println!("{}", v[0]);
}
