import sys
import heapq

INF = int(1e9)
input = sys.stdin.readline

n, m = map(int, input().split())
start = int(input())
graph = [[] for i in range (n+1)]

distance = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b,c))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    while q:
        dist, now = heapq.heappop(q)
        if dist > distance[now]:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            # dist = 현재노드까지 거리
            # i[1] 현재노드에 연결된 다른 노드와 현재노드 사이의 거리
            if cost < distance[i[0]]:
            # 현재 노드에서 다른 노드까지 가는 더 짧은 cost가 있는 경우
                distance[i[0]] = cost
                # 최소 cost로 변경,
                heapq.heappush(q, (cost, i[0]))
                # q에 start에서 i[0] 까지 가는 최소 cost 삽입