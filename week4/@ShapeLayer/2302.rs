use std::{io, cmp};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).ok();
  let n: i32 = puts.trim().parse::<i32>().unwrap();
  puts.clear();
  io::stdin().read_line(&mut puts).ok();
  let m: i32 = puts.trim().parse::<i32>().unwrap();
  let mut vip: Vec<i32> = Vec::new();
  vip.append(&mut vec![0]);
  for i in 0..m {
    puts.clear();
    io::stdin().read_line(&mut puts).ok();
    let s: i32 = puts.trim().parse::<i32>().unwrap();
    vip.append(&mut vec![s]);
  }
  vip.sort();
  vip.append(&mut vec![n+1]);
  let mut normal: Vec<i32> = Vec::new();
  for i in 1..vip.len() {
    normal.append(&mut vec![vip[i as usize] - vip[(i-1) as usize] - 1]);
  }
  let max = normal.iter().max().unwrap();
  let mut fibo: Vec<i32> = vec![0; cmp::max(n+1, 3) as usize];
  fibo[0] = 1;
  fibo[1] = 1;
  fibo[2] = 2;
  for i in 3..max+1 {
    fibo[i as usize] = fibo[(i-1) as usize] + fibo[(i-2) as usize];
  }
  let mut res = 1;
  for i in 0..normal.len() {
    res *= fibo[normal[i as usize] as usize];
  }
  println!("{}", res);
}