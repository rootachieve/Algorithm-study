s = input()
t = input()

queue = [t]

while queue:
    a = queue[0]
    del queue[0]
    
    if len(a)==len(s):
        if s==a:
            print(1)
            exit(0)
        else:
            continue
    
    if a[0] == a[-1]:
        if a[0] == 'A':
            queue.append(a[:-1])
        else:
            queue.append(a[:0:-1])
    elif a[0] == 'B':
        queue.append(a[:-1])
        queue.append(a[:0:-1])
        
print(0)