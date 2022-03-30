'''
1. 일반적으로 왼쪽 상단이 0,0 우측 하단이 m,n인데 이 문제는 해당 표현이 다르므로, 일반적인 표현에 맞게 좌표를 변경시켜준다.
x1,y1 부터 x2,y2까지 직사각형이 존재한다면, 아래 식으로 일반적인 좌표계에서 직사각형이 존재하는 좌표를 구할 수 있다.

for i in range(x1, x2):
    for j in range(y1, y2):
        dx = m-1-j
        dy = i
        
2. 직사각형이 존재하는 좌표를 1로 표시해두고, 0인곳에서 bfs를 수행한다.
3. bfs 수행 시 다음 이동 칸이 0일 경우 넓이를 증가시키는 방식으로 한 번의 bfs마다 탐색하는 넓이를 구할 수 있다.
        
'''



from collections import deque

m, n, k = map(int, input().split())
moves = [(0, 1), (0, -1), (-1, 0), (1, 0)]

graph = [[0]*n for _ in range(m)]
visited = [[False]*n for _ in range(m)]

for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    
    for i in range(x1, x2):
        for j in range(y1, y2):
            dx = m-1-j
            dy = i
            graph[dx][dy] = 1
            visited[dx][dy] = True

area_list = []

def bfs(x, y):
    area = 1
    q = deque([(x,y)])
    visited[x][y] = True
    while q:
        v = q.popleft()
        for move in moves:
            dx = v[0] + move[0]
            dy = v[1] + move[1]
            if 0<=dx<m and 0<=dy<n and graph[dx][dy]==0:
                if visited[dx][dy] == False:
                    q.append((dx, dy))
                    visited[dx][dy] = True
                    area+=1
    area_list.append(area)
    
for i in range(m):
    for j in range(n):
        if visited[i][j] == False:
            bfs(i, j)

print(len(area_list))
area_list.sort()
for i in range(len(area_list)):
    print(area_list[i], end=' ')
            