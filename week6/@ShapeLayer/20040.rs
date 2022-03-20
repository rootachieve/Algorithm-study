use std::io::{BufRead, BufWriter, Write};

struct Solution {
  parents: Vec<i32>
}
impl Solution {
  fn main(&mut self) {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let stdout = std::io::stdout();
    let mut stdout = BufWriter::new(stdout.lock());
    let mut puts = String::new();
    stdin.read_line(&mut puts).ok();
    let (n, m) = {
      let split: Vec<i32> = puts.split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
      (split[0], split[1])
    };
    self.parents = (0..n).collect::<Vec<i32>>();
    for i in 0..m {
      puts.clear();
      stdin.read_line(&mut puts).ok();
      let (a, b) = {
        let split: Vec<i32> = puts.split_whitespace()
          .map(|x| x.parse::<i32>().unwrap())
          .collect();
        (split[0], split[1])
      };
      if self.find(a) == self.find(b) {
        writeln!(stdout, "{}", i+1);
        return
      }
      self.merge(a, b);
    }
    writeln!(stdout, "0");
  }

  fn find(&mut self, puts: i32) -> i32 {
    if self.parents[puts as usize] == puts { return puts }
    self.parents[puts as usize] = self.find(self.parents[puts as usize]);
    self.parents[puts as usize]
  }
  fn merge(&mut self, a: i32, b: i32) {
    let (pa, pb) = (self.find(a), self.find(b));
    if pa < pb { self.parents[pb as usize] = pa; }
    else { self.parents[pa as usize] = pb; }
  }
}

fn main() {
  let mut solution = Solution {
    parents: Vec::new()
  };
  solution.main();
}