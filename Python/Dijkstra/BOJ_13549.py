'''
이 문제는 단순히 x-1, x+1 로의 거리 1과 2*x 로의 거리 0의 정보를 다 저장해 주고, 다익스트라를 수행하면 될 것으로 생각했다.
문제점
1. map이 max인 100000을 넘어가지 못하는것을 고려하지 않았다. 거리 정보 입력 시, -1, +1, *2등 했을때 map 넘어가는지 체크해야함
2. graph[1] 일때, i+1 과 2*i가 같기 때문에 예외적으로 처리해준다.
3. start가 end보다 클 경우, 예를 들어 5, 3인 경우 -1을 두번 하는 경우만 존재하므로 start >= end인 경우 start-end가 최단 시간이 된다.

+) 모든 지점마다의 거리정보를 다 미리 저장해두고 해야하므로 시간이 오래걸릴것 같음. 통과하긴 했지만 추후에 bfs등 다른 알고리즘으로 풀어보기.
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
graph[1].append((2,0))
graph[1].append((0,1))

for i in range(2, max+1):
    graph[i].append((i-1, 1))
    if i+1 <= max:
        graph[i].append((i+1, 1))
    if i*2 <= max:
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

if start >= end:
    print(start-end)
else:
    dijkstra(start)
    print(distance[end])