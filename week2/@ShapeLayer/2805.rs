// TIMEOUT
use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let (n, m) = {
    let split: Vec<i64> = puts.split_whitespace()
      .map(|i| i.parse::<i64>().unwrap())
      .collect();
    (split[0], split[1])
  };
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let trees: Vec<i64> = puts.split_whitespace()
    .map(|i| i.parse::<i64>().unwrap())
    .collect();
  let mut cut_line: i64 = *trees.iter().max().unwrap();
  let mut cuts: i64 = 0;
  while cuts < m {
    cut_line -= 1;
    cuts = 0;
    for i in 0..n {
      cuts += {
        let dt = trees[i as usize] - cut_line;
        if dt > 0 {
          dt
        } else {
          0
        }
      };
    }
  }
  println!("{}", cut_line);
}