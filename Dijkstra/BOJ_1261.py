# 각 칸으로 가는 최소비용을 distance 2차원 리스트에 저장
# 각 칸으로 가는 비용에 graph에 저장된 숫자 0 or 1을 더하면, 벽을 부순 경우 1이 추가된다.
# graph범위를 넘지 않는 범위에서, 각 노드는 그래프의 상하좌우의 노드로 이동 가능
# 따라서 상하좌우에 간선이 있다고 생각하고, 노드와 간선 관계를 하나씩 검사하면서 다익스트라 수행
# 벽을 부순 최소 횟수만 출력하면 되므로, 간선의 cost는 0으로 생각하고 벽이 있는 노드를 만났을 때만 1씩 더한다.

import sys
import heapq
INF = 1e9

input = sys.stdin.readline

m, n = map(int, input().split())
graph = [[] for _ in range(n)]
for i in range(n):
    graph[i] = list(map(int, input().rstrip()))

moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]

distance = [[INF] * m for _ in range(n)]

x, y = 0, 0
q = []
heapq.heappush(q, (0, x, y))
distance[x][y] = 0

while q:
    dist, x, y = heapq.heappop(q)
    if distance[x][y] < dist:
        continue
    for move in moves:
        nx = x + move[0]
        ny = y + move[1]
        if 0<=nx<n and 0<=ny<m:
            cost = dist + graph[nx][ny]
        else:
            continue
        if cost < distance[nx][ny]:
            distance[nx][ny] = cost
            heapq.heappush(q, (cost, nx, ny))

print(distance[n-1][m-1])