use std::{io, collections::VecDeque};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let t: usize = puts.trim().parse().unwrap();
  for _ in 0..t {
    let mut puts = String::new();
    io::stdin().read_line(&mut puts).unwrap();
    let (m, n, k) = {
      let split: Vec<usize> = puts.split_whitespace()
        .map(|i| i.parse::<usize>().unwrap())
        .collect();
      (split[0], split[1], split[2])
    };
    let mut map: Vec<Vec<bool>> = vec![vec![false; m]; n];
    for __ in 0..k {
      let mut puts = String::new();
      io::stdin().read_line(&mut puts).unwrap();
      let (x, y) = {
        let split: Vec<usize> = puts.split_whitespace()
          .map(|i| i.parse::<usize>().unwrap())
          .collect();
        (split[0], split[1])
      };
      map[y][x] = true;
    }
    let mut cnt = 0;
    for y in 0..n {
      for x in 0.. m {
        if map[y][x] {
          cnt += 1;
          map[y][x] = false;
          step(&mut map, m, n, x, y);
        }
      }
    }
    println!("{}", cnt);
  }
}

fn step(map: &mut Vec<Vec<bool>>, width: usize, height: usize, init_x: usize, init_y: usize) {
  let mut queue: VecDeque<Vec<i32>> = VecDeque::new();
  queue.push_back(vec![init_x as i32, init_y as i32]);
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
      if ux < 0 || ux >= width as i32 || uy < 0 || uy >= height as i32 { continue; }
      let nx: usize = ux as usize;
      let ny: usize = uy as usize;
      if !map[ny][nx] { continue; }
      map[ny][nx] = false;
      queue.push_back(vec![ux, uy]);
    }
  }
}