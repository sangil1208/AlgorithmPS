'''
DFS 문제

1. 0으로 초기화 된 촌수 배열
2. 연결된 곳 처음 방문 시마다 촌수 +1
3. dfs 끝난 후 촌수가 0이면 관계가 없는 것이므로 -1 출력
'''

def dfs(graph, v, visited):
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            ans[i] = ans[v] + 1
            dfs(graph, i, visited)
            

n = int(input())
x, y= map(int, input().split())

r = int(input())

graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]
ans = [0 for _ in range(n+1)]

for _ in range(r):
    i, j = map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)


dfs(graph, x, visited)

if ans[y] == 0:
    print(-1)
else:
    print(ans[y])
