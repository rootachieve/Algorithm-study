use std::io;

struct Solve {
  parents: Vec<i32>,
  size: Vec<i32>,
  is_tree: Vec<bool>
}
impl Solve {
  fn main(&mut self) {
    let mut loops = 0;
    loop {
      loops += 1;
      let mut puts = String::new();
      io::stdin().read_line(&mut puts).ok();
      let (m, n) = {
        let split: Vec<i32> = puts.split_whitespace()
          .map(|x| x.parse::<i32>().unwrap())
          .collect();
        (split[0], split[1])
      };
      if m == 0 && n == 0 { break; }
      self.parents = (0..m+1).collect::<Vec<i32>>();
      self.size = vec![1; (m+1) as usize];
      self.is_tree = vec![true; (m+1) as usize];
      for _i in 0..n {
        let mut puts = String::new();
        io::stdin().read_line(&mut puts).ok();
        let split: Vec<i32> = puts.split_whitespace()
          .map(|x| x.parse::<i32>().unwrap())
          .collect();
        self.merge(split[0], split[1]);
      }
      let mut counts = 0;
      for i in 1..m+1 {
        if self.is_tree[i as usize] { counts += 1; }
      }
      if counts == 0 {
        println!("Case {}: No trees.", loops);
      } else if counts == 1 {
        println!("Case {}: There is one tree.", loops);
      } else {
        println!("Case {}: A forest of {} trees.", loops, counts);
      }
    }
  }
  
  fn find(&mut self, puts: i32) -> i32 {
    if self.parents[puts as usize] == puts { return puts; }
    self.find(self.parents[puts as usize])
  }

  fn merge(&mut self, a: i32, b: i32) {
    let root_a = self.find(a);
    let root_b = self.find(b);
    if self.size[root_a as usize] > self.size[root_b as usize] {
      self.parents[root_b as usize] = root_a;
      self.size[root_a as usize] += self.size[root_b as usize];
      self.size[root_b as usize] = 0;
      if self.is_tree[root_b as usize] == false { self.is_tree[root_a as usize] = false; }
      self.is_tree[root_b as usize] = false;
    } else {
      self.parents[root_a as usize] = root_b;
      self.size[root_b as usize] += self.size[root_a as usize];
      self.size[root_a as usize] = 0;
      if self.is_tree[root_a as usize] == false { self.is_tree[root_b as usize] = false; }
      self.is_tree[root_a as usize] = false;
    }
  }
}

fn main() {
  let mut solve = Solve {
    parents: Vec::new(),
    size: Vec::new(),
    is_tree: Vec::new()
  };
  solve.main();
}