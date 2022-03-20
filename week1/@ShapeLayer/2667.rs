use std::{io, collections::VecDeque};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let n: usize = puts.trim().parse().unwrap();
  
  let mut map: Vec<Vec<bool>> = Vec::new();
  for _ in 0..n {
    let mut puts = String::new();
    io::stdin().read_line(&mut puts).unwrap();
    let puts = puts.trim().chars().collect::<Vec<char>>();
    let mut mapline: Vec<bool> = Vec::new();
    for content in puts {
      if content == '0' {
        mapline.append(&mut vec![false])
      } else {
        mapline.append(&mut vec![true])
      }
    }
    map.append(&mut vec![mapline]);
  }
  let mut cnt: Vec<usize> = Vec::new();
  for y in 0..n {
    for x in 0..n {
      if map[y][x] {
        map[y][x] = false;
        let res = step(&mut map, n as i32, vec![x as i32, y as i32]);
        cnt.append(&mut vec![res]);
      }
    }
  }
  cnt.sort();
  println!("{}", cnt.len());
  for nn in cnt { println!("{}", nn); }
}

fn step(map: &mut Vec<Vec<bool>>, size: i32, init: Vec<i32>) -> usize {
  let mut queue: VecDeque<Vec<i32>> = VecDeque::new();
  queue.push_back(init);
  let mut cnt = 1;
  let dx = vec![-1, 1, 0, 0];
  let dy = vec![0, 0, 1, -1];
  while queue.len() != 0 {
    let (x, y) = {
      let now = queue.pop_front().unwrap();
      (now[0], now[1])
    };
    for i in 0..4 {
      let ux: i32 = x + dx[i];
      let uy: i32 = y + dy[i];
      if ux < 0 || ux >= size || uy < 0 || uy >= size { continue; }
      let nx: usize = ux as usize;
      let ny: usize = uy as usize;
      if !map[ny][nx] { continue; }
      map[ny][nx] = false;
      cnt += 1;
      queue.push_back(vec![ux, uy]);
    }
  }
  cnt
}