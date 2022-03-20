use std::{io, cmp};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let n: i32 = puts.trim().parse::<i32>().unwrap();
  let (mut t, mut p, mut dp) = (vec![0; n as usize], vec![0; n as usize], vec![0; (n+1) as usize]);
  for i in 0..n {
    let mut puts = String::new();
    io::stdin().read_line(&mut puts).unwrap();
    let split: Vec<i32> = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    t[i as usize] = split[0];
    p[i as usize] = split[1];
  }
  for i in (0..n).rev() {
    if t[i as usize] + i > n { 
      dp[i as usize] = dp[(i+1) as usize];
      continue;
    }
    dp[i as usize] = cmp::max(dp[(i+1) as usize], p[i as usize] + dp[(i + t[i as usize]) as usize]);
  }
  println!("{}", dp.iter().max().unwrap());
}