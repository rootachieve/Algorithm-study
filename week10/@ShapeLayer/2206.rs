use std::{io, collections::VecDeque};

fn main() {
  let mut gets = String::new();
  io::stdin().read_line(&mut gets).ok();
  let (n, m) = {
    let split: Vec<i32> = gets.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1])
  };
  let mut map: Vec<Vec<bool>> = vec![vec![false; m as usize]; n as usize];
  let mut visits: Vec<Vec<Vec<bool>>> = vec![vec![vec![false; 2]; m as usize]; n as usize];
  for i in 0..n {
    gets.clear();
    io::stdin().read_line(&mut gets).ok();
    let split: Vec<String> = gets.trim().chars()
      .map(|x| String::from(x))
      .collect();
    for j in 0..m {
      map[i as usize][j as usize] = split[(j) as usize].trim().parse::<i32>().unwrap() == 1;
    }
  }
  let mut queue: VecDeque<(i32, i32, i32, i32)> = VecDeque::new();
  let offset: Vec<(i32, i32)> = vec![(1, 0), (-1, 0), (0, 1), (0, -1)];
  queue.push_back((0, 0, 1, 1));
  while !queue.is_empty() {
    let now = queue.pop_front().unwrap();
    if now.0 == n-1 && now.1 == m-1 {
      println!("{}", now.2);
      return
    }
    for i in 0..4 {
      let mut next = (now.0 + offset[i as usize].0, now.1 + offset[i as usize].1, now.2+1, now.3);
      if next.0 < 0 || next.0 >= n || next.1 < 0 || next.1 >= m { continue; }
      if !map[next.0 as usize][next.1 as usize] {
        if next.3 == 1 && !visits[next.0 as usize][next.1 as usize][0] {
          queue.push_back(next);
          visits[next.0 as usize][next.1 as usize][0] = true;
        } else if next.3 == 0 && !visits[next.0 as usize][next.1 as usize][1] {
          queue.push_back(next);
          visits[next.0 as usize][next.1 as usize][1] = true;
        }
      } else {
        if next.3 == 1 {
          next.3 = 0;
          queue.push_back(next);
          visits[next.0 as usize][next.1 as usize][1] = true;
        }
      }
    }
  }
  println!("-1");
}