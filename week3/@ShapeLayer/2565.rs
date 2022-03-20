use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let n: i32 = puts.trim().parse().unwrap();
  let mut puts_arr: Vec<(i32, i32)> = vec![(-1, -1); (n+1) as usize];
  puts_arr[0] = (0, 0);
  for i in 1..n+1 {
    let mut puts = String::new();
    io::stdin().read_line(&mut puts).unwrap();
    let puts_split: Vec<i32> = puts.split_whitespace()
      .map(|i| i.parse::<i32>().unwrap())
      .collect();
    puts_arr[i as usize] = (puts_split[0], puts_split[1]);
  }
  puts_arr.sort_by_key(|k| k.0);
  let mut counts: Vec<i32> = vec![0; (n+1) as usize];
  for i in 1..n+1 {
    let (mut max, mut idx) = (0, 0);
    for j in 0..i {
      if max < counts[j as usize] && puts_arr[j as usize].1 < puts_arr[i as usize].1 {
        max = counts[j as usize];
        idx = j;
      }
    }
    counts[i as usize] = counts[idx as usize] + 1;
  }
  println!("{}", n - counts.iter().max().unwrap());
}