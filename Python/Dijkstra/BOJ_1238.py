# 최단거리 문제로, 다익스트라 알고리즘을 이용해서 푼다.
# 하지만 왕복 최단거리를 구해야 하므로, 모든 노드에 대해 다익스트라 알고리즘 계산 결과를 2차원 배열에 저장한다.
# 그 후, 모든 노드로부터 주어진 x점까지의 왕복 최단거리를 구한다.
# 위에서 구한 왕복 최단거리들을 리스트에 저장 후, 최댓값을 출력한다.

import sys
import heapq
input = sys.stdin.readline

INF = 1e9

n, m, x = map(int, input().split())

graph = [[] for _ in range(n+1)]
distance = [INF]*(n+1)

time = [[] for _ in range(n+1)]
result = []

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

def dijkstra(start):
    q = []
    distance[start] = 0
    heapq.heappush(q, (0,start))
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

for i in range(1, n+1):
    dijkstra(i)
    time[i] = list(distance)
    distance = [INF]*(n+1)
    
for i in range(1, n+1):
    result.append(time[i][x]+time[x][i])
        
print(max(result))
    