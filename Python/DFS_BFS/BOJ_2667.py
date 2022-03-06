from collections import deque
import sys

input = sys.stdin.readline
n = int(input())
graph = [list(input().rstrip()) for i in range(n)]
visited = [[False]*n for _ in range(n)]
total = 0
house =[]
    
moves = [(1,0), (0,-1), (-1,0), (0,1)]
#상,하,좌,우 로 가능한 이동을 표현

def bfs(graph, i, j, visited):
    queue = deque()
    queue.extend([(i,j)])
    visited[i][j] = True
    cnt = 1
    while queue:
        v = queue.popleft()
        #cnt
        for move in moves:
            x = v[0] + move[0]
            y = v[1] + move[1]
            if x>=0 and x<n and y>=0 and y<n and int(graph[x][y]) == 1 and not visited[x][y]:
                queue.append((x, y))
                visited[x][y] = True
                cnt+=1
    house.append(cnt)

#상하좌우로 이동 후 배열 내에 포함되고, 방문한적이 없으며 1인 경우에 큐에 삽입, 이 경우 cnt를 1씩 증가시켜
#한 단지 내에 집이 몇 개 있는지 구할 수 있다.

for i in range(n):
    for j in range(n):
        if int(graph[i][j])==1 and not visited[i][j]:
            total += 1
            bfs(graph, i, j, visited)
#bfs를 요소가 1이고 방문한 적이 없는 곳 부터 시작한다. bfs가 수행될 때 마다 1씩 증가시키면 총 단지수를 얻을 수 있다.
            
print(total)
house.sort()
for i in range(len(house)):
    print(house[i])
