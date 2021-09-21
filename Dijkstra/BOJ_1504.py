# 다익스트라 문제이지만, 함정이 몇 가지 있다. 먼저, 양 방향 그래프라고 했으므로 간선 입력을 양방향으로 해줘야 한다.
# 또한 특정 노드 x,y를 지나는 경로는 1->x->y->n 과 1->y->x->n 두 가지가 있으므로 두 가지중 최솟값을 구해야 한다.
# 다익스트라 함수의 리턴값을 distance배열로 하면 특정 노드에서 다른 노드까지의 최단 경로가 담긴 리스트를 반환하고 이를 사용해 추가적인 연산 가능하다.

import sys
import heapq
INF = 1e9

input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
result = []

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))


x, y = map(int, input().split())


def dijkstra(start):
    distance = [INF]*(n+1)
    q = []
    distance[start] = 0
    heapq.heappush(q, (0, start))
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance

a = dijkstra(1)
v1 = dijkstra(x)
v2 = dijkstra(y)

result.append(a[x]+v1[y]+v2[n])
result.append(a[y]+v2[x]+v1[n])

if min(result) >= INF:
    print(-1)
else:
    print(int(min(result)))


