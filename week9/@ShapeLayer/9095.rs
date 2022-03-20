use std::io;

fn main() {
  let mut gets = String::new();
  io::stdin().read_line(&mut gets).ok();
  let t = gets.trim().parse::<i32>().unwrap();
  let mut arr: Vec<i32> = vec![-1; t as usize];
  for i in 0..t {
    gets.clear();
    io::stdin().read_line(&mut gets).ok();
    let n = gets.trim().parse::<i32>().unwrap();
    arr[i as usize] = n;
  }
  let size: i32 = *arr.iter().max().unwrap();
  let mut counts: Vec<i32> = vec![-1; (size+1) as usize];
  counts[1] = 1;
  counts[2] = 2;
  counts[3] = 4;
  for i in 4..size+1 {
    counts[i as usize] = counts[(i-3) as usize] + counts[(i-2) as usize] + counts[(i-1) as usize];
  }
  for i in 0..t {
    println!("{}", counts[arr[i as usize] as usize]);
  }
}