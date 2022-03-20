use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).ok();
  let n: i32 = puts.trim().parse::<i32>().unwrap();
  puts.clear();
  io::stdin().read_line(&mut puts).ok();
  let mut arr: Vec<i32> = puts.split_whitespace()
    .map(|x| x.parse::<i32>().unwrap())
    .collect();
  arr.sort();
  println!("{}", arr[((n-1)/2) as usize]);
}