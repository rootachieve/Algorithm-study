use std::io;

fn main() {
  let mut puts = String::new();
  io::stdin().read_line(&mut puts).unwrap();
  let n: i32 = puts.trim().parse::<i32>().unwrap();
  let mut dp: Vec<i32> = vec![0; 100001];
  dp[1] = 3;
  dp[2] = 7;
  for i in 3..n+1 {
    dp[i as usize] = (dp[(i-1) as usize] * 2 + dp[(i-2) as usize]) % 9901;
  }
  println!("{}", dp[n as usize]);
}