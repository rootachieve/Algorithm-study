use std::{io, mem};

fn get_dist(ax: i32, ay: i32, bx: i32, by: i32) -> i32 {
  (ax-bx).pow(2) + (ay-by).pow(2)
}

fn find_gcd(mut a: i32, mut b: i32) -> i32 {
  while b != 0 {
    mem::swap(&mut b, &mut a);
    b %= a;
  }
  a
}

fn main() {
  let mut gets = String::new();
  io::stdin().read_line(&mut gets).ok();
  let (xs, ys) = {
    let split: Vec<i32> = gets.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1])
  };
  gets.clear();
  io::stdin().read_line(&mut gets).ok();
  let (mut xe, mut ye, mut dx, mut dy) = {
    let split: Vec<i32> = gets.split_whitespace()
      .map(|x| x.parse::<i32>().unwrap())
      .collect();
    (split[0], split[1], split[2], split[3])
  };
  let gcd = find_gcd(dx, dy);
  dx /= gcd;
  dy /= gcd;
  let mut min = 100000000;
  let (mut solx, mut soly) = (-1, -1);
  loop {
    let dist = get_dist(xs, ys, xe, ye);
    if dist < min {
      solx = xe;
      soly = ye;
      min = dist;
    } else {
      break;
    }
    xe += dx;
    ye += dy;
  }
  println!("{} {}", solx, soly);
}