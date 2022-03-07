'''
시작 칸부터 마지막 칸까지 가는 최소 칸 수
bfs를 수행하면서 한칸 지나갈때마다 횟수를 증가시킨다.
특정 칸으로의 이동은 여러 다른 칸으로부터 올 수 있다.
이동 시 현재 칸의 횟수 + 1과 이동 하려는 칸을 비교해서 더 작은 수를 저장한다.
이렇게 하면 이동 횟수를 저장한 이차원 리스트의 마지막 요소에 최소 칸 수가 저장된다.
파이썬에서 queue는 deque 라이브러리를 통해 사용한다.
'''


import sys
from collections import deque
INF = int(1e9)
input = sys.stdin.readline
n, m = map(int, input().split())

graph = []
for _ in range(n):
    graph.append(list(map(int, input().rstrip())))

result = [[INF]*m for _ in range(n)]
result[0][0] = 1

moves = [(0,1),(0,-1),(1,0),(-1,0)]

visited = [[False] * (m) for _ in range(n)]

def bfs(graph, x, y, visited):
    queue = deque([(x, y)])
    visited[x][y] = True
    while queue:
        x, y = queue.popleft()
        for move in moves:
            dx = x + move[0]
            dy = y + move[1]
            if 0<=dx<n and 0<=dy<m:
                if not visited[dx][dy] and graph[dx][dy] == 1:
                    queue.append((dx, dy))
                    visited[dx][dy] = True
                    if result[x][y] + 1 < result[dx][dy]:
                        result[dx][dy] = result[x][y] + 1

                
bfs(graph, 0, 0, visited)
print(result[n-1][m-1])