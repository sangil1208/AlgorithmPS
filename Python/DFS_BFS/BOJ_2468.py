'''
BFS문제. 입력받은 땅의 높이 중 최소, 최대를 저장한다.
최소 최대 사이의 범위를 비의 양의 범위로 설정하고, 각 비의 양 별로 안전한 영역 개수를 센다.
모든 땅이 같은 높이인 경우, 해당 높이의 비 양에 대해서만 수행되므로 모두 잠기는걸로 처리된다.
하지만 모든 땅의 높이가 7이고, 비가 4만큼 온다면 하나도 잠기지 않아 안전 영역은 1개가 된다.
이 경우를 처리해주어, 모든 땅의 높이가 같다면 1을 출력하도록 해야한다.
'''


import sys
from collections import deque
import copy
input = sys.stdin.readline


def bfs(x, y, visited):
    q = deque([(x, y)])
    visited[x][y] = True
    while q:
        v = q.pop()
        for move in moves:
            dx = v[0] + move[0]
            dy = v[1] + move[1]
            if 0<=dx<n and 0<=dy<n and visited[dx][dy] == False:
                q.append((dx,dy))
                visited[dx][dy] = True



if __name__ == "__main__":
    n = int(input())
    
    graph = []
    max_list = []
    min_list = []
    
    cnt_list = []
    
    moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    for _ in range(n):
        temp = list(map(int, input().split()))
        graph.append(temp)
        max_list.append(max(temp))
        min_list.append(min(temp))

    for i in range(min(min_list), max(max_list)+1):
        cnt = 0
        temp_graph = copy.deepcopy(graph)
        visited = [[False]*n for _ in range(n)]
        for a in range(n):
            for b in range(n):
                if temp_graph[a][b]<=i:
                    visited[a][b] = True
        
        for a in range(n):
            for b in range(n):
                if visited[a][b] == False:
                    bfs(a, b, visited)
                    cnt+=1
        cnt_list.append(cnt)

    if len(cnt_list)==1 and min(cnt_list)==0:
        print(1)
    else:
        print(max(cnt_list))
    


    
    
    