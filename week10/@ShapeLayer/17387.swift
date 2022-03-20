import Foundation

func ccw(_ p1: (Int, Int), _ p2: (Int, Int), _ p3: (Int, Int)) -> Int {
  let op = (p1.0*p2.1 + p2.0*p3.1 + p3.0*p1.1) - (p1.0*p3.1 + p2.0*p1.1 + p3.0*p2.1)
  if op > 0 { return 1 }
  else if op < 0 { return -1 }
  else { return 0 }
}

func isIntersect(_ p1: inout (Int, Int), _ p2: inout (Int, Int), _ p3: inout (Int, Int), _ p4: inout (Int, Int)) -> Bool {
  let p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4)
  let p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2)
  if p1p2 == 0 && p3p4 == 0 {
    if p1 > p2 { (p1, p2) = (p2, p1) }
    if p3 > p4 { (p3, p4) = (p4, p3) }
    return p3 <= p2 && p1 <= p4
  }
  return p1p2 <= 0 && p3p4 <= 0
}

var gets = readLine()!.components(separatedBy: " ")
var (p1, p2) = ((Int(gets[0])!, Int(gets[1])!), (Int(gets[2])!, Int(gets[3])!))
gets = readLine()!.components(separatedBy: " ")
var (p3, p4) = ((Int(gets[0])!, Int(gets[1])!), (Int(gets[2])!, Int(gets[3])!))
if isIntersect(&p1, &p2, &p3, &p4) { print(1) }
else { print(0) }