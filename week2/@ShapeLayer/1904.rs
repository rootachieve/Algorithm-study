use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let n: i64 = puts.trim().parse().unwrap();
  let mut cache: Vec<i32> = vec![-1; 1000001];
  cache[1] = 1;
  cache[2] = 2;
  for i in 3..n+1 {
    cache[i as usize] = (cache[(i-1) as usize] + cache[(i-2) as usize]) % 15746;
  }
  println!("{}", cache[n as usize]);
}