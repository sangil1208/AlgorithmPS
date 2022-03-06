# 입력으로 주어진 a,b는 서로와 관계를 맺고 있으므로 graph[a][b]와 graph[b][a] 에 모두 1을 저장한다.
# 플로이드 워셜을 수행한 후 최솟값을 비교해 케빈 베이컨 수가 가장 적은 사람을 찾아야 한다.
# 하지만 플로이드 워셜 수행 후 결과 리스트에 INF값이 들어있으므로, INF가 있는 리스트 요소는 0으로 바꿔준다(관계가 없음을 의미)

import sys
input = sys.stdin.readline
INF = 1e9

n, m = map(int, input().split())
graph = [[INF]*(n+1) for _ in range(n+1)]

for a in range(1, n+1):
    for b in range(1, n+1):
        if a == b:
            graph[a][b] = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])

for a in range(n+1):
    for b in range(n+1):
        if graph[a][b] == INF:
            graph[a][b] = 0

temp = [0]*(n+1)
min = INF
index = 0
for i in range(1, n+1):
    temp[i] = sum(graph[i])
    if temp[i] < min:
        min = temp[i]
        index = i

print(index)
