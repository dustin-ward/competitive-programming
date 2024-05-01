use std::io;
use std::collections::HashSet;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let t = line.trim().parse::<i32>().unwrap();

    for _ in 0..t {
        line = String::new();
        io::stdin().read_line(&mut line);
        let recording = line.trim().to_string();

        let mut sounds = HashSet::<String>::new();
        line = String::new();
        io::stdin().read_line(&mut line);
        while line.trim() != "what does the fox say?" {
            sounds.insert(line.trim().split(" ").collect::<Vec<_>>()[2].to_string().clone());

            line = String::new();
            io::stdin().read_line(&mut line);
        }

        for word in recording.split(" ") {
            if !sounds.contains(word) {
                print!("{} ", word);
            }
        }
        print!("\n");
    }
}
