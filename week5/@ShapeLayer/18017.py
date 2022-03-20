from decimal import *
getcontext().prec = 100
a, b = map(Decimal, input().split())
print((a + b) / (1 + a*b/(299792458**2)))