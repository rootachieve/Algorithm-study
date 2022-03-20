use std::{io, collections::VecDeque};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).ok();
  let (m, n, h) = {
    let split: Vec<i32> = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1], split[2])
  };
  let mut map: Vec<Vec<Vec<i32>>> = vec![vec![Vec::new(); n as usize]; h as usize];
  let mut queue: VecDeque<(i32, i32, i32, i32)> = VecDeque::new();
  for k in 0..h {
    for i in 0..n {
      puts.clear();
      io::stdin().read_line(&mut puts).ok();
      map[k as usize][i as usize] = puts.split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
      for j in 0..m {
        if map[k as usize][i as usize][j as usize] == 1 {
          queue.push_back((k, i, j, 0));
        }
      }
    }
  }
  puts.clear();
  let mut time_elapsed: i32 = 0;
  let mut queued: Vec<Vec<Vec<bool>>> = vec![vec![vec![false; m as usize]; n as usize]; h as usize];
  while !queue.is_empty() {
    let dot = queue.pop_front().unwrap();
    map[dot.0 as usize][dot.1 as usize][dot.2 as usize] = 1;
    time_elapsed = dot.3;
    for i in vec![(1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, 1), (0, 0, -1)] {
      let (nk, ni, nj) = (dot.0 + i.0, dot.1 + i.1, dot.2 + i.2);
      if nk < 0 || nk >= h || ni < 0 || ni >= n || nj < 0 || nj >= m { continue; }
      if map[nk as usize][ni as usize][nj as usize].abs() == 1 { continue; }
      if queued[nk as usize][ni as usize][nj as usize] { continue; }
      queued[nk as usize][ni as usize][nj as usize] = true;
      queue.push_back((nk, ni, nj, dot.3+1));
    }
  }
  let mut flag = false;
  for flat in map {
    for row in flat {
      if row.contains(&0) { flag = true; }
    }
  }
  if flag { println!("-1"); }
  else { println!("{}", time_elapsed) };
}