#대표적인 그리디 문제로 보인다.
#동전 종류중 큰것부터 차례로 나눈다.

n, m = map(int, input().split())
types = [0] * n

for i in range(n):
    types[i] = int(input())

types.sort(reverse=True)
cnt = 0

for type in types:
    cnt += m//type
    m = m%type

print(cnt)
    