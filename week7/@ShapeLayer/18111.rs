use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).ok();
  let (n, m, b) = {
    let split: Vec<i32> = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1], split[2])
  };
  let mut blocks: Vec<i32> = Vec::new();
  for _i in 0..n {
    puts.clear();
    io::stdin().read_line(&mut puts).ok();
    let split = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap());
    for num in split {
      blocks.append(&mut vec![num]);
    }
  }
  let mut res: Vec<(i32, i32)> = Vec::new();
  for base in 0..257 {
    let mut inv = b;
    let mut elapsed = 0;
    let mut flag = false;
    for block in &blocks {
      if *block > base {
        inv += block - base;
        elapsed += (block - base) * 2;
      } else if *block < base {
        inv -= base - block;
        elapsed += base - block;
      }
    }
    if inv < 0 { continue; }
    res.append(&mut vec![(elapsed, base)]);
  }
  res.sort_by_key(|k| k.0);
  let mut c: Vec<(i32, i32)> = Vec::new();
  for i in 0..res.len() {
    if res[i].0 == res[0].0 { c.append(&mut vec![res[i]]); }
  }
  c.sort_by_key(|k| k.1);
  c.reverse();
  println!("{} {}", c[0].0, c[0].1);
}