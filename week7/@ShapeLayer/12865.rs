use std::{io, cmp};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).ok();
  let (n, k) = {
    let split: Vec<i32> = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1])
  };
  let mut values: Vec<i32> = Vec::new();
  let mut weights: Vec<i32> = Vec::new();
  for _i in 0..n {
    puts.clear();
    io::stdin().read_line(&mut puts).ok();
    let split: Vec<i32> = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    weights.append(&mut vec![split[0]]);
    values.append(&mut vec![split[1]]);
  }
  let mut bag: Vec<Vec<i32>> = vec![vec![0; (n+1) as usize]; (k+1) as usize];
  for weight in 1..k+1 {
    for object in 1..n+1 {
      if weights[(object-1) as usize] <= weight {
        bag[weight as usize][object as usize] = cmp::max(
          bag[(weight-weights[(object-1) as usize]) as usize][(object-1) as usize] + values[(object-1) as usize],
          bag[weight as usize][(object-1) as usize]
        );
      } else {
        bag[weight as usize][object as usize] = bag[weight as usize][(object-1) as usize];
      }
    }
  }
  println!("{}", bag[k as usize][n as usize]);
}