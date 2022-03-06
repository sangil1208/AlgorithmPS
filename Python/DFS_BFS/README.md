# DFS
- 그래프에서 깊은 부분을 우선적으로 탐색
- Stack 사용
- 기본 리스트에서 append()와 pop() 메서드 사용하면 스택 자료구조와 동일하게 동작
- 탐색 수행에 O(N) 시간 소요
- Stack을 사용하므로 재귀함수를 이용하면 구현이 간단

## Base Code 

```python

#graph는 2차원 list
visited = [False] * 9

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

```