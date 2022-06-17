target = input()
ab = input()
for i in range(len(ab)-len(target)):
    if ab[-1]=='A':
        ab = ab[:-1]
    else:
        ab = ab[-2::-1]
print(1 if ab==target else 0)