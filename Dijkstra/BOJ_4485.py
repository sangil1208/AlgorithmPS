
'''
각 칸에는 해당 칸으로 이동시 감소하는 루피 수가 있으므로, 상하좌우로 이동하여 목적지까지 갈때, 지나가는 칸에 써있는 수 합이 최소가 되도록.
각 칸에 써있는 숫자는 해당 칸으로 이동 가능한 칸에서 해당 칸으로 이동 시 필요한 cost로 생각 (감소하는 화폐 수)
처음 큐에 삽입하는 값은 (0,0)에서 시작하므로 graph[0][0]에 있는 값만큼 화폐가 감소한다. 따라서 큐에 (graph[0][0], 0, 0) 을 삽입한다.
이 의미는 (cost, x, y) 의 의미는 시작점에서 x,y 까지 가는 최소 비용이 cost라는 의미이다.
이후에는 다익스트라 알고리즘 수행, graph[n-1][n-1] 의 값을 출력 (0,0에서 n-1,n-1까지 가는 최소 cost 출력)
'''

import sys
import heapq
INF = 1e9

input = sys.stdin.readline
cnt = 0
while True:
    cnt = cnt + 1
    
    n = int(input())
    if n==0:
        break
    graph = [[] for _ in range(n)]
    for i in range(n):
        graph[i] = list(map(int, input().split()))

    moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    distance = [[INF] * n for _ in range(n)]

    x, y = 0, 0
    q = []
    heapq.heappush(q, (graph[x][y], x, y))
    distance[x][y] = graph[x][y]

    while q:
        dist, x, y = heapq.heappop(q)
        if distance[x][y] < dist:
            continue
        for move in moves:
            nx = x + move[0]
            ny = y + move[1]
            if 0<=nx<n and 0<=ny<n:
                cost = dist + graph[nx][ny]
            else:
                continue
            if cost < distance[nx][ny]:
                distance[nx][ny] = cost
                heapq.heappush(q, (cost, nx, ny))
    result = distance[n-1][n-1]
    
    print("Problem %d: %d" %(cnt, result))