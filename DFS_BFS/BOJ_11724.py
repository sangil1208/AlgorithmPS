#dfs수행 후, 첫 dfs에서 방문하지 않는 노드로 bfs시작. 이거 반복해서 모든 노드 방문될때까지.
#dfs 수행 횟수가 cc의갯수이다
#런타임 에러를 방지하기 위해 재귀 호출 제한을 증가시키고, 입력을 sys.stdin.readline()으로 받는다.
#아니면 재귀를 사용하지 않는 bfs로 구현한다

import sys
sys.setrecursionlimit(10**6)

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)
cnt = 0

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(graph, v, visited):
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)


for i in range(1,n+1): #visited[0] 이 포함되지 않도록 1부터 범위지정
    if not visited[i]:
        dfs(graph, i, visited)
        cnt += 1
        
print(cnt)