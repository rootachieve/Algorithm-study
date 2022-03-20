use std::{io};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let n: i32 = puts.trim().parse::<i32>().unwrap();
  let mut max: Vec<i32> = Vec::new();
  for i in 0..n+1 {
    let res: Vec<i32> = processing(n, i);
    if res.len() > max.len() {
      max = res;
    }
  }
  max.pop();
  println!("{}", max.len());
  println!("{}", max.iter().map(|i| i.to_string() + " ").collect::<String>());
}

fn processing(a: i32, b: i32) -> Vec<i32> {
  let mut now: i32 = b;
  let mut list: Vec<i32> = Vec::new();
  list.append(&mut vec![a]);
  list.append(&mut vec![b]);
  let mut i: i32 = 1;
  while now >= 0 {
    now = list[(i-1) as usize] - list[i as usize];
    list.append(&mut vec![now]);
    i += 1;
  }
  list
}