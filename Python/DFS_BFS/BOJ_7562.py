'''
BFS를 이용하면 1회 이동으로 갈 수 있는 곳들을 모두 체크 한 후 2회 이동으로 갈 수 있는 곳들을 체크하기 때문에,
목적지에 가장 먼저 도달한 횟수가 최소 횟수가 된다.
이를 이용해서 목적지에 값이 들어온 경우 바로 종료하도록 해 시간 초과를 해결한다.

=> moves에 8개 값을 입력하다 보니 실수가 발생해 엄청 헤맸다.. moves 값 정확히 입력하도록 주의하자
'''


from collections import deque
import math
INF = math.inf

moves = [(-1, -2), (-1, 2), (-2, -1), (-2, 1), (1, -2), (1, 2), (2, -1), (2, 1)]

def bfs(graph, xs, ys, xf, yf):
    q = deque([(xs, ys)])
    graph[xs][ys] = 0
    while q:
        x, y = q.popleft()
        for move in moves:
            dx = x + move[0]
            dy = y + move[1]
            if 0<=dx<n and 0<=dy<n and graph[dx][dy] > graph[x][y] + 1:
                graph[dx][dy] = graph[x][y] + 1
                if dx == xf and dy == yf:
                    return
                q.append((dx, dy))
  

if __name__ == "__main__":
    
    t = int(input())
    for _ in range(t):
        n = int(input())
        xs, ys = map(int, input().split())
        xf, yf = map(int, input().split())

        graph = [[INF]*n for _ in range(n)]

        if xs == xf and ys == yf:
            print(0)
        else:
            bfs(graph, xs, ys, xf, yf)
            print(graph[xf][yf])
