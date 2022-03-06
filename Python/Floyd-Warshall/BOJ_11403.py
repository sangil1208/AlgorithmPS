# 모든 정점에서 모든 정점으로 가는 경로를 구해야 하므로 Floyd warshall 알고리즘을 이용한다.
# 입력을 받을 2차원 리스트를 선언하고, 입력을 받은 후 해당 리스트를 체크하며 최단경로를 갱신해 다른 2차원 리스트에 저장한다.
# 경로가 없으면 INF값이 유지되므로, 2차원 리스트 요소를 모두 탐색하면서 값이 INF면 0, 아니면 1을 출력한다.
# 문제에서 [i][i]는 항상 0이고, 이 경우 0으로 출력하라고 한 것을 잘 체크해서 graph[i][i] 의 값은 항상 INF로 둔다.

import sys
input = sys.stdin.readline
INF = 1e9

N = int(input())
graph = [[INF]*(N+1) for _ in range(N+1)]
inputmap = [[] for _ in range(N+1)]

for i in range(N):
    inputmap[i] = list(map(int, input().split()))
    
for a in range(N):
    for b in range(N):
        if inputmap[a][b]==1:
            graph[a+1][b+1] = 1
    
for k in range(1, N+1):
    for a in range(1, N+1):
        for b in range(1, N+1):
            graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])


for a in range(1, N+1):
    for b in range(1, N+1):
        if graph[a][b] == INF:
            print(0, end=' ')
        else:
            print(1, end=' ')
    print()
        