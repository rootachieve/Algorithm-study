use std::{io, collections::VecDeque};

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).ok();
  let n = puts.trim().parse().unwrap();
  let mut stack: VecDeque<i32> = VecDeque::new();
  let mut cnts: Vec<i32> = vec![0; n as usize];
  let mut init = 0;
  for i in 0..n {
    puts.clear();
    io::stdin().read_line(&mut puts).ok();
    let input = puts.trim().parse().unwrap();
    if input > init {
      for j in init+1..input+1 {
        stack.push_back(j);
      }
      cnts[i] = input-init;
      init = input;
    } else if *stack.iter().last().unwrap_or_else(|| &-1) != input {
      println!("NO");
      return
    }
    stack.pop_back();
  }
  let mut body: Vec<&str> = Vec::new();
  for num in cnts {
    for _i in 0..num {
      body.append(&mut vec!["+"]);
    }
    body.append(&mut vec!["-"]);
  }
  println!("{}", body.join("\n"));
}