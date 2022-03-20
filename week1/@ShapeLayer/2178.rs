use std::{io, collections::VecDeque};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let (n, m) = {
    let split: Vec<i32> = puts.split_whitespace()
      .map(|i| i.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1])
  };
  let mut map: Vec<Vec<bool>> =  Vec::new();
  let mut visit: Vec<Vec<bool>> = vec![vec![false; m as usize]; n as usize];
  for _ in 0..n {
    let mut puts = String::new();
    io::stdin().read_line(&mut puts).unwrap();
    let puts = puts.trim().chars().collect::<Vec<char>>();
    let mut mapline: Vec<bool> = Vec::new();
    for dot in puts {
      if dot == '0' { mapline.append(&mut vec![false]); }
      else { mapline.append(&mut vec![true]); }
    }
    map.append(&mut vec![mapline]);
  }

  // BFS
  visit[0][0] = true;
  let mut queue: VecDeque<(i32, i32)> = VecDeque::new();
  queue.push_back((0, 0));
  let dx = vec![-1, 1, 0, 0];
  let dy = vec![0, 0, 1, -1];
  let mut trace: Vec<Vec<i32>> = vec![vec![0; m as usize];n as usize];
  while queue.len() != 0 {
    let (x, y) = queue.pop_front().unwrap();
    for i in 0..4 {
      let nx = x + dx[i];
      let ny = y + dy[i];
      if nx < 0 || nx >= m || ny < 0 || ny >= n { continue; }
      if !map[ny as usize][nx as usize] { continue; }
      if visit[ny as usize][nx as usize] { continue; }
      trace[ny as usize][nx as usize] = trace[y as usize][x as usize] + 1;
      visit[ny as usize][nx as usize] = true;
      queue.push_back((nx, ny));
    }
  }

  /* // Printing step map.
  for i in 0..n {
    println!("{:?}", trace[i as usize]);
  }*/
  println!("{}", trace[(n as usize) - 1][(m as usize) - 1] + 1)
}