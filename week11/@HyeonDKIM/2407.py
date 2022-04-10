# 2407 조합

import sys
import math

input = sys.stdin.readline

n, m = map(int, input().split())

# nCm => n! / (n-m)! * m!
up = math.factorial(n)
down = (math.factorial(n-m)) * (math.factorial(m))

print(up//down)