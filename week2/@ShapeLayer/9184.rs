use std::io;

struct Solve {
  cache: Vec<Vec<Vec<i64>>>
}

impl Solve {
  fn main(&mut self) {
    loop {
      let mut puts = String::new();
      io::stdin().read_line(&mut puts).unwrap();
      let (a, b, c) = {
        let split: Vec<i64> = puts.split_whitespace()
          .map(|i| i.parse::<i64>().unwrap())
          .collect();
        (split[0], split[1], split[2])
      };
      if a == -1 && b == -1 && c == -1 {
        break;
      }
      println!("w({}, {}, {}) = {}", a, b, c, self.w(a, b, c));
    }
  }

  fn w(&mut self, a: i64, b: i64, c: i64) -> i64 {
    if self.cache[(a+50) as usize][(b+50) as usize][(c+50) as usize] == -100 {
      if a <= 0 || b <= 0 || c <= 0 {
        self.cache[(a+50) as usize][(b+50) as usize][(c+50) as usize] = 1;
      } else if a > 20 || b > 20 || c > 20 {
        self.cache[(a+50) as usize][(b+50) as usize][(c+50) as usize] = self.w(20, 20, 20);
      } else if a < b && b < c {
        self.cache[(a+50) as usize][(b+50) as usize][(c+50) as usize] = self.w(a, b, c-1) + self.w(a, b-1, c-1) - self.w(a, b-1, c);
      }
      else {
        self.cache[(a+50) as usize][(b+50) as usize][(c+50) as usize] = self.w(a-1, b, c) + self.w(a-1, b-1, c) + self.w(a-1, b, c-1) - self.w(a-1, b-1, c-1);
      }
    }
    return self.cache[(a+50) as usize][(b+50) as usize][(c+50) as usize];
  }
}

fn main() {
  let mut solve = Solve {
    cache: vec![vec![vec![-100; 102]; 102]; 102]
    /* -50 ~ 50 => 101
      When indexing, follow the rule:
      actually = i64 - 50
      for ex.  (act) -50, -50, -50 => (idx) 0, 0, 0
               (act) 0, 1, 2       => (idx) 50, 51, 52
    */
  };
  solve.main();
}