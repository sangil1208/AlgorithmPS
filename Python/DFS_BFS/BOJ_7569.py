'''
7576 토마토 문제와 동일하지만, 3차원 리스트를 사용하는 문제.
2차원 리스트의 반복으로 3차원 리스트를 구현하는것이 고려해야 할 사항 훨씬 많아 3차원 리스트 선택.
역시 1인 곳에서 끝까지 bfs 수행하고, 다른 1인 곳에서 bfs 수행하면서 더 작은값으로 갱신 가능하면 갱신하는 방식은 시간초과 발생.


==> 한 시간 단위씩, graph가 1인 값부터 bfs를 수행하는것으로 해결했다.
1시간단위마다, 큐에 있는 값 각각에 대해 bfs를 수행한다.
또한, 값 갱신은 graph 값이 0일때만 진행하므로 0이 한번씩 다 다른 값으로 채워진 이후 (토마토가 모두 익은 이후) 부터는 값 갱신이 없다.
따라서 값 갱신을 계속 수행하는 첫 구현 방법에 비해 시간 소요가 적다.
'''

import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, q):
    while q:
        for _ in range(len(q)):
            z, x, y = queue.popleft()
            for move in moves:
                dz = z + move[0]
                dx = x + move[1]
                dy = y + move[2]
                if 0<=dx<n and 0<=dy<m and 0<=dz<h and graph[dz][dx][dy] == 0:
                    graph[dz][dx][dy] = graph[z][x][y] + 1
                    q.append((dz, dx, dy))

if __name__ == "__main__":
    
    cnt_list = []
    m, n, h = map(int, input().split())
    moves = [(1,0,0), (-1,0,0), (0,1,0), (0,-1,0), (0,0,1),(0,0,-1)]
    graph = [[] for _ in range(h)]
    queue = deque()
    
    for i in range(h):
        for _ in range(n):
            graph[i].append(list(map(int, input().split())))
    
    cnt = 0
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if graph[i][j][k] == 1:
                    queue.append((i, j, k))
                if graph[i][j][k] != 0:
                    cnt += 1
    
    if cnt == (m*n*h):
        print(0)
        quit()
        
    bfs(graph, queue)
    
    max_list = []
    
    for i in range(h):
        for j in range(n):
            for k in range(m):
                max_list.append(graph[i][j][k])
                if graph[i][j][k] == 0:
                    print(-1)
                    quit()
            
    print(max(max_list)-1)
    