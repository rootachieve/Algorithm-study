use std::{io, cmp};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let str_a: Vec<String> = puts.trim().chars()
    .map(|i| i.to_string())
    .collect();
  puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let str_b: Vec<String> = puts.trim().chars()
    .map(|i| i.to_string())
    .collect();
  let na = str_a.len();
  let nb = str_b.len();
  let mut map: Vec<Vec<i32>> = vec![vec![0; (nb+1) as usize]; (na+1) as usize];
  for i in 1..na+1 {
    for j in 1..nb+1 {
      // String indexing: i-1
      // `map` length is n+1 * n+1
      if str_a[(i-1) as usize] == str_b[(j-1) as usize] {
        map[i as usize][j as usize] = map[(i-1) as usize][(j-1) as usize] + 1;
      } else {
        map[i as usize][j as usize] = cmp::max(map[(i-1) as usize][j as usize], map[i as usize][(j-1) as usize]);
      }
    }
  }

  let mut lcs = String::new();
  let (mut i, mut j) = (na, nb);
  while i != 0 && j != 0 {
    let now = map[i as usize][j as usize];
    if now != map[(i-1) as usize][j as usize] && now != map[i as usize][(j-1) as usize] {
      lcs.push_str(&str_a[(i-1) as usize].clone());
    }
    /*if now == map[(i-1) as usize][j as usize] { i -= 1; }
    else if now == map[i as usize][(j-1) as usize] { j -= 1; }
    else { i-=1; j-=1; }*/
    
    if now != map[(i-1) as usize][j as usize] { j -= 1; }
    if now != map[i as usize][(j-1) as usize] { i -= 1; }
    
    if now == 0 { break; }
  }
  lcs = lcs.chars().rev().collect::<String>();
  println!("{}", lcs.len());
  println!("{}", lcs);
}