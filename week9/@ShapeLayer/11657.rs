use std::io;

const INF: i64 = 2000000000;

fn main() {
  let mut gets = String::new();
  io::stdin().read_line(&mut gets).ok();
  let (n, m) = {
    let split: Vec<i64> = gets.split_whitespace()
      .map(|x| x.parse::<i64>().unwrap())
      .collect();
    (split[0], split[1])
  };
  let mut forwards: Vec<(i64, i64, i64)> = Vec::new();
  let mut dist: Vec<i64> = vec![INF; (n+1) as usize];
  for _m in 0..m {
    gets.clear();
    io::stdin().read_line(&mut gets).ok();
    let (s, e, t) = {
      let split: Vec<i64> = gets.split_whitespace()
        .map(|x| x.parse::<i64>().unwrap())
        .collect();
      (split[0], split[1], split[2])
    };
    forwards.append(&mut vec![(s, e, t)]);
  }
  let mut is_ncycle = false;
  dist[1] = 0;
  for i in 0..n {
    for j in 0..m {
      let now = forwards[j as usize].0;
      let next = forwards[j as usize].1;
      let cost = forwards[j as usize].2;
      if dist[now as usize] != INF && dist[next as usize] > dist[now as usize] + cost {
        dist[next as usize] = dist[now as usize] + cost;
        if i == n-1 { is_ncycle = true; }
      }
    }
  }
  if is_ncycle { println!("-1"); }
  else {
    for i in 2..n+1 {
      if dist[i as usize] == INF { println!("-1"); }
      else { println!("{}", dist[i as usize]); }
    }
  }
}