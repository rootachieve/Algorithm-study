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
  let mut map: Vec<Vec<i32>> = vec![vec![-1; m as usize]; n as usize];
  let mut aircons: Vec<(i32, i32)> = Vec::new();
  for i in 0..n {
    puts.clear();
    io::stdin().read_line(&mut puts).ok();
    let row: Vec<i32> = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    for j in 0..m {
      if row[j as usize] == 9 {
        aircons.append(&mut vec![(i, j)]);
      }
    }
    map[i as usize] = row;
  }
  let mut res: Vec<Vec<i32>> = vec![vec![0; m as usize]; n as usize];
  let mut queue: VecDeque<(i32, i32, i32)> = VecDeque::new(); // i, j, direction
  // direction: 0 up / 1 left / 2 down / 3 right
  for aircon in aircons {
    queue.push_back((aircon.0 - 1, aircon.1, 0));
    queue.push_back((aircon.0 + 1, aircon.1, 2));
    queue.push_back((aircon.0, aircon.1 - 1, 1));
    queue.push_back((aircon.0, aircon.1 + 1, 3));
    res[aircon.0 as usize][aircon.1 as usize] = 1;
  }
  while !queue.is_empty() {
    let now = queue.pop_front().unwrap();
    if now.0 < 0 || now.0 >= n || now.1 < 0 || now.1 >= m {
      continue;
    }
    res[now.0 as usize][now.1 as usize] = 1;
    let tile = map[now.0 as usize][now.1 as usize];
    if tile == 0 {
      if now.2 == 0 { queue.push_back((now.0-1, now.1, 0)); }
      else if now.2 == 1 { queue.push_back((now.0, now.1-1, 1)); }
      else if now.2 == 2 { queue.push_back((now.0+1, now.1, 2)); }
      else { queue.push_back((now.0, now.1+1, 3)); }
    } else if tile == 1 {
      if now.2 == 0 { queue.push_back((now.0-1, now.1, 0)); } // up
      else if now.2 == 2 { queue.push_back((now.0+1, now.1, 2)); } // down
      // horizontal will be ignored
    } else if tile == 2 {
      if now.2 == 1 { queue.push_back((now.0, now.1-1, 1)); } // left
      else if now.2 == 3 { queue.push_back((now.0, now.1+1, 3)); } // right
      // vertical will be ignored
    } else if tile == 3 {
      if now.2 == 0 { queue.push_back((now.0, now.1+1, 3)); } // up to right
      else if now.2 == 1 { queue.push_back((now.0+1, now.1, 2)); } // left to down
      else if now.2 == 2 { queue.push_back((now.0, now.1-1, 1)); } // down to left
      else { queue.push_back((now.0-1, now.1, 0)); } // right to up
    } else if tile == 4 {
      if now.2 == 0 { queue.push_back((now.0, now.1-1, 1)) } // up to left
      else if now.2 == 1 { queue.push_back((now.0-1, now.1, 0)) } // left to up
      else if now.2 == 2 { queue.push_back((now.0, now.1+1, 3)) } // down to right
      else { queue.push_back((now.0+1, now.1, 2)) } // right to down
    }
  }
  let mut sum: i32 = 0;
  for arr in res {
    sum += arr.iter().sum::<i32>();
  }
  println!("{}", sum);
}