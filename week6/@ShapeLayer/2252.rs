use std::{io, collections::VecDeque};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).ok();
  let (n, m) = {
    let split: Vec<i32> = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1])
  };
  let mut map: Vec<Vec<i32>> = vec![Vec::new(); (n+1) as usize];
  let mut incomes: Vec<i32> = vec![0; (n+1) as usize];
  for _i in 0..m {
    let mut puts = String::new();
    io::stdin().read_line(&mut puts).ok();
    let (a, b) = {
      let split: Vec<i32> = puts.split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
      (split[0], split[1])
    };
    map[a as usize].append(&mut vec![b]);
    incomes[b as usize] += 1;
  }
  let mut queue = VecDeque::new();
  for i in 1..n+1 {
    if incomes[i as usize] == 0 {
      queue.push_back(i);
    }
  }
  let mut res: Vec<i32> = Vec::new();
  while !queue.is_empty() {
    let now = queue.pop_front().unwrap();
    res.append(&mut vec![now]);
    for n in &map[now as usize] {
      incomes[*n as usize] -= 1;
      if incomes[*n as usize] == 0 {
        queue.push_back(*n);
      }
    }
  }
  println!("{}", res.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(" "));
}