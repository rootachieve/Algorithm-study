use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let n: i32 = puts.trim().parse::<i32>().unwrap();
  let res = {
    if n % 2 == 1 { "SK" }
    else { "CY" }
  };
  println!("{}", res);
}