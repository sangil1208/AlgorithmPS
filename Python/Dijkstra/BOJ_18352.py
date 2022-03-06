'''
다익스트라 알고리즘 이용하여 최단거리를 distance 배열에 저장 후,
distance배열의 값이 k와 같은 요소의 번호를 출력한다.
'''
import sys
import heapq

INF =int(1e9)
input = sys.stdin.readline

n, m, k, x = map(int, input().split())

graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

for i in range(m):
    start, end = map(int, input().split())
    graph[start].append((end, 1))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(x)

flag = 0

for i in range(1, n+1):
    if distance[i] == k:
        print(i)
        flag = 1

if flag == 0:
    print(-1)