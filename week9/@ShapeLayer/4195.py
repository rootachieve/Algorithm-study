size = []
parents = []
hashmap = dict()
index = 0

def find(n):
    return n if parents[n] == n else find(parents[n])

def merge(a: int, b: int):
    pa, pb = find(a), find(b)
    if pa > pb:
        parents[b] = pa
        parents[pb] = pa
        size[pa] += size[pb]
    elif pa < pb:
        parents[a] = pb
        parents[pa] = pb
        size[pb] += size[pa]

def push_hashmap(puts: str):
    global index, size, parents
    if puts not in hashmap:
        hashmap[puts] = index
        index += 1
        parents += [len(parents)]
        size += [1]

if __name__ == '__main__':
    for _ in range(int(input())):
        f = int(input())
        parents = []
        size = []
        hashmap = dict()
        index = 0
        for i in range(f):
            a, b = input().split()
            push_hashmap(a)
            push_hashmap(b)
            merge(hashmap[a], hashmap[b])
            print(size[find(hashmap[a])])