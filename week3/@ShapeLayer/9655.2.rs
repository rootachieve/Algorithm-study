use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let mut n: i32 = puts.trim().parse::<i32>().unwrap();
  let mut current: i32 = -1; // 0: SK, 1: CY
  while n != 0 {
    if n > 3 {
      n -= 3;
    } else {
      n -= 1;
    }
    current = (current + 1) % 2;
  }
  let res = {
    if current == 0 { "SK" }
    else { "CY" }
  };
  println!("{}", res);
}