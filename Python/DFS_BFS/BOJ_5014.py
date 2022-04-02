'''
1. 각 층에 도착할 수 있는 최소 횟수를 저장하는 graph생성.
2. 시작점부터 +up 과 -down에 해당하는 이동을 bfs로 수행
3. 층의 가능한 범위를 벗어나지 않고 수행한 이동이 이전 이동의 횟수보다 작을 경우 graph 갱신
4. bfs 수행 이후 goal에 해당하는 graph값이 INF인 경우는 도달할 수 없는 경우이므로 use the stars 출력
5. 4번의 경우가 아닌 경우는 bfs 수행 이후 goal에 해당하는 graph값을 출력하면 해당 goal 층까지 가기 위한 최소 이동 횟수
'''

from collections import deque
import math

INF = math.inf
F, S, G, U, D = map(int, input().split())

graph = [INF] * (F+1)
moves = [U, D*(-1)]
graph[S] = 0

def bfs(start):
    q = deque([(start, 0)])
    while q:
        v = q.popleft()
        for move in moves:
            next = v[0] + move
            if 1<=next<=F and graph[next] > v[1]+1:
                graph[next] = v[1]+1
                q.append((next, v[1]+1))
                
bfs(S)

if graph[G] == INF:
    print("use the stairs")
else:
    print(graph[G])