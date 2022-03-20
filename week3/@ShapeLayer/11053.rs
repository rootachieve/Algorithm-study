use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let n: i32 = puts.trim().parse::<i32>().unwrap();
  let mut puts = String::from("0 ");
  io::stdin().read_line(&mut puts).unwrap();
  let arr: Vec<i32> = puts.split_whitespace()
    .map(|i| i.parse::<i32>().unwrap())
    .collect();
  let mut counts = vec![0; (n+1) as usize];
  for i in 1..n+1 {
    let (mut maximum, mut idx) = (0, 0);
    for j in 0..i {
      if maximum < counts[j as usize] && arr[j as usize] < arr[i as usize] {
        maximum = counts[j as usize];
        idx = j;
      }
    }
    counts[i as usize] = counts[idx as usize] + 1;
  }
  println!("{}", counts.iter().max().unwrap());
}