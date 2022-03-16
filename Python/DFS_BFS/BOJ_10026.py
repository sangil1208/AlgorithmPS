'''
['RRRBB', 'GGBBB', 'BBBRR', 'BBRRR', 'RRRRR']
-> 이건 요소 수정 불가 ex) graph[i][j] = 'G' 불가
-> 수정하려면 리스트로 저장해야함
[['R', 'R', 'R', 'B', 'B'], ['G', 'G', 'B', 'B', 'B'], ['B', 'B', 'B', 'R', 'R'], ['B', 'B', 'R', 'R', 'R'], ['R', 'R', 'R', 'R', 'R']]
-> 이건 요소 수정 가능

색깔이 같은 경우 탐색을 수행하는 bfs를 구현해 그래프에 대해 수행하고,  -> 적록색약이 아닌 사람이 봤을 때 구역의 수
이후 그래프의 R을 G로 바꾼 후 위에서 수행한 bfs를 그대로 수행해준다.  -> 적록색약인 사람이 봤을 때 구역의 수
'''

import sys
from collections import deque
input = sys.stdin.readline

moves = [(1,0), (-1,0), (0,1), (0,-1)]
def bfs(visited, graph, x, y):
    q = deque([(x,y)])
    visited[x][y] = True
    while q:
        v = q.pop()
        for move in moves:
            dx = v[0] + move[0]
            dy = v[1] + move[1]
            if 0<=dx<n and 0<=dy<n:
                if graph[x][y] == graph[dx][dy] and visited[dx][dy] == False:
                    visited[dx][dy] = True
                    q.append((dx, dy))
                    

if __name__ == "__main__":
    
    cnt = 0
    cnt_s = 0
    
    n = int(input())
    graph = []
    visited = [[False]*n for _ in range(n)]

    for _ in range(n):
        graph.append(list(input().rstrip()))
        
    for i in range(n):
        for j in range(n):
            if visited[i][j] == False:
                bfs(visited, graph, i, j)
                cnt += 1
    
    for i in range(n):
        for j in range(n):
            if graph[i][j] =='R':
                graph[i][j] = 'G'
                
    visited = [[False]*n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if visited[i][j] == False:
                bfs(visited, graph, i, j)
                cnt_s += 1
    
    
    print(cnt, end=' ')
    print(cnt_s)