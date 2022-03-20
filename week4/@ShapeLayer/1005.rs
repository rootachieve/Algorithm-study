// Kahn's algorithm
use std::{io::{BufRead, BufWriter, Write}, collections::VecDeque};

fn main() {
  let stdin = std::io::stdin();
  let mut stdin = stdin.lock();
  let stdout = std::io::stdout();
  let mut stdout = BufWriter::new(stdout.lock());
  // Input number of testcase (t)
  let mut puts = String::new();
  stdin.read_line(&mut puts).ok();
  let t: i32 = puts.trim().parse::<i32>().unwrap();
  // Loop for testcases
  for _ in 0..t {
    // Input number of buildings (n), number of constructing order (k)
    puts.clear();
    stdin.read_line(&mut puts).ok();
    let (n, k) = {
      let split: Vec<i32> = puts.split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
      (split[0], split[1])
    };
    // Input time that consumes during construct (Dn)
    puts = String::from("0 ");
    stdin.read_line(&mut puts).ok();
    let consumes: Vec<i32> = puts.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    // Input constructing rules (Xn, Yn)
    let mut map: Vec<Vec<i32>> = vec![Vec::new(); (n+1) as usize];
    let mut requirements: Vec<Vec<i32>> = vec![Vec::new(); (n+1) as usize];
    let mut incomes: Vec<i32> = vec![0; (n+1) as usize];
    for _i in 0..k {
      puts.clear();
      stdin.read_line(&mut puts).ok();
      let (prev, next) = {
        let split: Vec<i32> = puts.split_whitespace()
          .map(|x| x.parse::<i32>().unwrap())
          .collect();
        (split[0], split[1])
      };
      map[prev as usize].append(&mut vec![next]);
      requirements[next as usize].append(&mut vec![prev]);
      incomes[next as usize] += 1;
    }
    // Input target building that user can be winner (w)
    puts.clear();
    stdin.read_line(&mut puts).ok();
    let w: i32 = puts.trim().parse::<i32>().unwrap();
    // Init process
    let mut elapsed_time: Vec<i32> = vec![0; (n+1) as usize];
    let mut queue: VecDeque<i32> = VecDeque::new();
    for i in 1..(n+1) {
      if incomes[i as usize] == 0 { queue.push_back(i); }
    }
    // Process
    while !queue.is_empty() {
      let now: i32 = queue.pop_front().unwrap();
      let mut prev_elapsed_times: Vec<i32> = Vec::new();
      for i in 0..requirements[now as usize].len() {
        prev_elapsed_times.append(&mut vec![elapsed_time[requirements[now as usize][i as usize] as usize]]);
      }
      let mut prev_elapsed_time = 0;
      match prev_elapsed_times.iter().max() {
        Some(x) => prev_elapsed_time = *x,
        None => prev_elapsed_time = 0
      }
      elapsed_time[now as usize] = consumes[now as usize] + prev_elapsed_time;
      for i in 0..map[now as usize].len() {
        if incomes[map[now as usize][i as usize] as usize] > 0 {
          incomes[map[now as usize][i as usize] as usize] -= 1;
        }
        if incomes[map[now as usize][i as usize] as usize] == 0 {
          queue.push_back(map[now as usize][i as usize]);
        }
      }
    }
    writeln!(stdout, "{}", elapsed_time[w as usize]).ok();
  }
}