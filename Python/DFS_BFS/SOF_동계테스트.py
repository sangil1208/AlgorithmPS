'''
얼음 내부에 존재하는 공기와 아닌 공기를 파악하기 위해 bfs수행.
처음 0,0 에서 bfs해서 탐색 안된 부분은 내부 공기

이렇게 내부 공기를 파악 후, 외부 공기와 2면이상 맞닿은 부분 얼음 제거하는것을 반복

bfs 1회만 수행하고, 이후에는 제거한 얼음을 외부 공기로 바꾸는 방법 <- 틀림
-> 이렇게 하면 제거된 얼음 부분이 내부 공기가 될 수도 있는 케이스 고려되지 않음
'''

import sys
from collections import deque

moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def bfs(graph, visited, x, y):
    q = deque([(x, y)])
    visited[x][y] = True
    graph[x][y] = 3
    while q:
        v = q.popleft()
        for move in moves:
            nx = v[0] + move[0]
            ny = v[1] + move[1]
            if 0<=nx<n and 0<=ny<m:
                if graph[nx][ny] == 0 and visited[nx][ny] == False:
                    q.append((nx, ny))
                    air[nx][ny] = True
                    visited[nx][ny] = True

input = sys.stdin.readline
n, m = map(int, input().split())

graph = []
for _ in range(n):
    graph.append(list(map(int, input().rstrip().split())))

air = [[False]*m for _ in range(n)]

result = 0

while True:
    
    visited = [[False]*m for _ in range(n)]
    bfs(graph, visited, 0, 0)
    
    change_list = []
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1:
                cnt = 0
                for move in moves:
                    nx = move[0] + i
                    ny = move[1] + j
                    if 0<=nx<n and 0<=ny<m and air[nx][ny] == True:
                        cnt+=1
                if cnt >= 2:
                    change_list.append((i, j))
                    
    if len(change_list) == 0:
        break
    else:
        result += 1
        
    for c in change_list:
        graph[c[0]][c[1]] = 0
    
print(result)