use std::{io, mem};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).ok();
  let (a, b) = {
    let split: Vec<i64> = puts.split_whitespace()
      .map(|x| x.parse::<i64>().unwrap())
      .collect();
    (split[0], split[1])
  };
  let n: i64 = b / a;
  let range = (n as f64).sqrt() as i64;
  let mut res: Vec<(i64, i64, i64)> = Vec::new();
  for i in 1..range+1 {
    if n % i == 0 {
      if find_gcd(i as i64, n/i as i64) == 1 {
        res.append(&mut vec![((i as i64)*a, (n/i as i64)*a, (i as i64 + n/i as i64)*a)]);
      }
    }
  }
  res.sort_by_key(|k| k.2);
  println!("{} {}", res[0].0, res[0].1);
}

fn find_gcd(mut a: i64, mut b: i64) -> i64 {
  while b != 0 {
    mem::swap(&mut b, &mut a);
    b %= a;
  }
  a
}