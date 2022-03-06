# 방향그래프에서 시작점에서 다른 모든 정점으로의 최단 경로 -> 다익스트라 알고리즘 이용
# 최악의 경우에도 O(V^2)이 아닌 O(ElogV)를 보장하기 위해 우선순위 큐를 사용해 구현
# 우선순위 큐는 하나의 데이터를 삽입 및 삭제할 때 시간 복잡도가 O(logN)이다

import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())

start = int(input())
graph = [[] for i in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b,c))
    
def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))  # (거리, 노드)
    distance[start] = 0
    while q:  # 큐가 비어있지 않다면
        dist, now = heapq.heappop(q)  # 가장 거리 짧은 노드 꺼내기
        # 현재 노드가 이미 처리된 적이 있으면 무시한다
        if distance[now] < dist:
            continue
        
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
                
dijkstra(start)

for i in range(1, n+1):
    if distance[i] == INF:
        print("INF")
    else:
        print(distance[i])
    
        
