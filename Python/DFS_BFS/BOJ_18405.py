'''
7569번 문제와 비슷하게 해결
==> 한 시간 단위씩, graph가 1인 값부터 bfs를 수행하는것으로 해결했다.
1시간단위마다, 큐에 있는 값 각각에 대해 bfs를 수행한다.
또한, 값 갱신은 graph 값이 0일때만 진행하므로 0이 한번씩 다 다른 값으로 채워진 이후 부터는 값 갱신이 없다.
값 갱신을 계속 수행하는 구현 방법에 비해 시간 소요가 적다.

이 문제에서 헤맨 이유

1) 바이러스 번호가 작은 것 부터 증식하는것을 구현하지 않았다.
start.sort()

start_sorted = []

for i in range(len(start)):
    start_sorted.append(start[i][1])
    
위 코드를 통해 바이러스 번호 작은 것 부터 bfs 시작하도록 했다.

2) s의 범위가 0부터 시작한다

s가 0인 경우는 
if time == s:
    break
를 만족시킬 수 없어서 bfs가 종료되지 않는다. 

if s==0:
    print(graph[x-1][y-1])
else:
    bfs(start_sorted)
    print(graph[x-1][y-1])
    
위와 같이 s가 0인 경우는 별도 처리를 해 주었다.

'''


from collections import deque

n, k = map(int, input().split())
graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))

s, x, y = map(int, input().split())
moves = [(0,1), (1,0), (0,-1), (-1,0)]



def bfs(start_sorted):
    q = deque(start_sorted)
    time = 0
    while q:
        time += 1
        length = len(q)
        for _ in range(length):
            v = q.popleft()
            for move in moves:
                da = v[0] + move[0]
                db = v[1] + move[1]
                if 0<=da<n and 0<=db<n and graph[da][db] == 0:
                    q.append((da, db))
                    graph[da][db] = graph[v[0]][v[1]]
        if time == s:
            break


start = []

for i in range(n):
    for j in range(n):
        if graph[i][j] != 0:
            start.append((graph[i][j], (i, j)))

start.sort()

start_sorted = []

for i in range(len(start)):
    start_sorted.append(start[i][1])

if s==0:
    print(graph[x-1][y-1])
else:
    bfs(start_sorted)
    print(graph[x-1][y-1])
