use std::{io, collections::VecDeque};

struct Process {
  visit: Vec<bool>,
  map: Vec<Vec<usize>>,
  result: Vec<usize>
}

impl Process {
  fn main(&mut self) {
    let mut puts = String::new();
    io::stdin().read_line(&mut puts).unwrap();
    let puts: Vec<usize> = puts.split_whitespace()
      .map(|i| i.parse::<usize>().unwrap())
      .collect();
    let (n, m, v) = (puts[0], puts[1], puts[2]);
    self.map = vec![Vec::new(); n+1];

    for _ in 0..m {
      let mut puts = String::new();
      io::stdin().read_line(&mut puts).unwrap();
      let puts: Vec<usize> = puts.split_whitespace()
        .map(|i| i.parse::<usize>().unwrap())
        .collect();
      
      self.map[puts[0]].push(puts[1]);
      self.map[puts[1]].push(puts[0]);
    }
    for i in 1..(n + 1) {
      self.map[i].sort();
    }

    self.visit = vec![false; n+1];
    self.dfs(v);
    for res in &self.result {
      print!("{} ", res);
    }
    println!("");


    self.result = Vec::new();
    self.visit = vec![false; n+1];
    self.bfs(v);
    for res in &self.result {
      print!("{} ", res);
    }
    println!("");
  }

  fn dfs(&mut self, n: usize) {
    self.visit[n] = true;
    self.result.append(&mut vec![n]);
    for i in 0..self.map[n].len() {
      let dot: usize = self.map[n][i];
      if self.visit[dot] {
        continue;
      }
      self.dfs(dot);
    }
  }

  fn bfs(&mut self, init: usize) {
    let mut queue: VecDeque<usize> = VecDeque::new();
    queue.push_back(init);
    while queue.len() != 0 {
      let now = queue.pop_front().unwrap();
      if self.visit[now] {
        continue;
      }
      self.visit[now] = true;
      self.result.append(&mut vec![now]);
      for dot in &self.map[now] {
        queue.push_back(*dot);
      }
    }
  }
}

fn main() {
  let mut process = Process {
    visit: Vec::new(),
    map: Vec::new(),
    result: Vec::new()
  };
  process.main();
}