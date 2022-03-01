'''

'''

import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

max = 100000
distance = [INF] * (max+1)

start, end = map(int, input().split())
graph = [[] for _ in range(max+1)]

graph[0].append((1,1))
graph[1].append((2,0), (0,1))

for i in range(2, end):
    graph[i].append((i-1, 1))
    graph[i].append((i+1, 1))
    graph[i].append((2*i, 0))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    while q:
        dist, now = heapq.heappop(q)
        if dist > distance[now]:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

if start == end:
    print(0)
else:
    dijkstra(start)
    print(distance[end])