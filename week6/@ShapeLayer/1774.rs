use std::io;

struct Solution {
  parent: Vec<i32>,
  sums: f32
}
impl Solution {
  fn main(&mut self) {
    let mut puts = String::new();
    io::stdin().read_line(&mut puts).ok();
    let (n, m) = {
      let split: Vec<i32> = puts.split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
      (split[0], split[1])
    };
    let mut dots: Vec<(i32, i32)> = Vec::new(); // x, y
    for _i in 0..n {
      puts.clear();
      io::stdin().read_line(&mut puts).ok();
      let (x, y) = {
        let split: Vec<i32> = puts.split_whitespace()
          .map(|x| x.parse::<i32>().unwrap())
          .collect();
        (split[0], split[1])
      };
      dots.append(&mut vec![(x, y)]);
    }
    let mut distances: Vec<(i32, i32, f32)> = Vec::new(); // dot1 dot2 distance
    self.parent = (0..n+1).collect::<Vec<i32>>();
    for i in 0..n {
      for j in i..n {
        if i == j { continue; }
        distances.append(&mut vec![(i+1, j+1, (((dots[i as usize].0 - dots[j as usize].0) as f32).powf(2.0) + ((dots[i as usize].1 - dots[j as usize].1) as f32).powf(2.0)).sqrt())]);
      }
    }
    distances.sort_by(|a, b| a.partial_cmp(b).unwrap());
    for _i in 0..m {
      puts.clear();
      io::stdin().read_line(&mut puts).ok();
      let (a, b) = {
        let split: Vec<i32> = puts.split_whitespace()
          .map(|x| x.parse::<i32>().unwrap())
          .collect();
        (split[0], split[1])
      };
      self.sums += (((dots[(a-1) as usize].0 - dots[(b-1) as usize].0) as f32).powf(2.0) + ((dots[(a-1) as usize].1 - dots[(b-1) as usize].1) as f32).powf(2.0)).sqrt();
      self.merge(a, b);
    }
    for i in 0..distances.len() {
      let now = distances[i];
      if self.find(now.0) == self.find(now.1) { continue; }
      self.sums += (((dots[distances[i as usize].0 as usize].0 - dots[distances[i as usize].1 as usize].0) as f32).powf(2.0) + ((dots[distances[i as usize].0 as usize].1 - dots[distances[i as usize].1 as usize].1) as f32).powf(2.0)).sqrt();
      self.merge(now.0, now.1);
    }
    println!("{:?}", self.parent);
    println!("{}", self.sums);
  }

  fn find(&mut self, puts: i32) -> i32 {
    if self.parent[puts as usize] == puts { return puts }
    self.find(self.parent[puts as usize])
  }

  fn merge(&mut self, a: i32, b: i32) {
    let (pa, pb) = (self.find(a), self.find(b));
    if pa < pb { self.parent[pb as usize] = pa; }
    else { self.parent[pa as usize] = pb; }
  }
}

fn main() {
  let mut solution = Solution {
    parent: Vec::new(),
    sums: 0.0
  };
  solution.main();
}