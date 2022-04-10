# 1620 포켓몬 마스터 이다솜
import sys

N, M = map(int, input().split())

input = sys.stdin.readline
pokemon = {}
for i in range(1, N+1):
    i = str(i)
    pokemon[i] = input().rstrip()

print(pokemon) # 기존 딕셔너리
reverse_pokemon = dict(map(reversed, pokemon.items())) # 기존 딕셔너리 뒤집어서 새로운 키-값 만들기
print(reverse_pokemon) # 뒤집은 딕셔너리

for i in range(M):
    tmp = input().rstrip()
    if tmp in pokemon: # tmp -> key값이 기존 딕셔너리에 있으면
        a = pokemon[tmp] # 기존 딕셔너리에서 찾아쓰기
    else: # key값이 없으면
        a = reverse_pokemon[tmp] # 뒤집은 딕셔너리에 무조건 있음 ㅇㅇ
    print(a)