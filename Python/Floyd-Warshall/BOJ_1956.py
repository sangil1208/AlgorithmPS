'''
모든 점으로부터 모든 점으로의 최단 거리를 구한 후,
v -> v'-> v 로 돌아오는 경로 중 최소값을 구한다.
v-> v' -> v'' -> v 경로도 있을 수 있지만, v->v'->v 경로보다 항상 크기 때문에 v->v'->v 경우만 고려하면 된다.
가능한 cycle이 없을 경우, cycles 리스트에 INF를 저장하게 하여 cycle리스트의 최소가 INF일때 -1을 출력하도록 한다.
python3로 제출하면 시간초과 발생하는데, pypy3로 제출하면 시간초과 발생하지 않는다.
BOJ에 있는 문제 중 플로이드 워셜 알고리즘을 사용해야 하는 문제 처럼 N^3의 복잡도를 갖는 문제는 pypy3로 제출해야 통과한다.
'''


import sys
input = sys.stdin.readline

INF = int(1e9)

n, m = map(int, input().split())

graph = [[INF]*(n+1) for _ in range(n+1)]

for a in range(1, n+1):
    for b in range(1, n+1):
        if a==b:
            graph[a][b] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = c
    
for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

cycles = []

for a in range(1, n+1):
    for b in range(1, n+1):
        if a==b:
            continue
        if graph[a][b] == INF or graph[b][a] == INF:
            cycles.append(INF)
            continue
        cycles.append((graph[a][b] + graph[b][a]))
        
        
if min(cycles) == INF:
    print(-1)
else:
    print(min(cycles))