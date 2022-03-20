use std::{io, collections::VecDeque};
use std::fmt;

struct Dot {
  now_pos: i32,
  count: i32
}

impl fmt::Debug for Dot {
  fn fmt(&self, f: &mut fmt::Formatter) -> fmt:: Result {
    write!(f, "(now_pos: {}, count: {})", self.now_pos, self.count)
  }
}

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let (n, k) = {
    let split: Vec<i32> = puts.split_whitespace()
      .map(|i| i.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1])
  };
  let subin = Dot {
    now_pos: n,
    count: 0
  };
  let mut queue: VecDeque<Dot> = VecDeque::new();
  let mut visit: Vec<bool> = vec![false; 100001];
  queue.push_back(subin);
  loop {
    let dot = queue.pop_front().unwrap();
    visit[dot.now_pos as usize] = true;
    //println!("{} {:?}", dot.now_pos, queue);
    if dot.now_pos == k {
      println!("{}", dot.count);
      break;
    }
    if (dot.now_pos - 1) >= 0 {
      if visit[(dot.now_pos - 1) as usize] == false {
        queue.push_back(Dot {
          now_pos: dot.now_pos - 1,
          count: dot.count + 1
        });
      }
    }
    if (dot.now_pos + 1) <= 100000 {
      if visit[(dot.now_pos + 1) as usize] == false {
        queue.push_back(Dot {
          now_pos: dot.now_pos + 1,
          count: dot.count + 1
        });
      }
    }
    if (dot.now_pos * 2) <= 100000 {
      if visit[(dot.now_pos * 2) as usize] == false {
        queue.push_back(Dot {
          now_pos: dot.now_pos * 2,
          count: dot.count + 1
        });
      }
    }
  }
}