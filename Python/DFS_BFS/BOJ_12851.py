from collections import deque
import math

INF = math.inf

def bfs(start):
    q = deque([start])
    while q:
        v = q.popleft()
        nexts = [v-1, v+1, 2*v]
        for next in nexts:
            if 0<=next<=100000:
                if graph[next] == INF:
                    graph[next] = graph[v]+1
                    cnt[next] = cnt[v]
                    q.append(next)
                elif graph[v]+1 == graph[next]: # 다시 방문했는데 최단거리일 경우
                    cnt[next] += cnt[v] # v까지 가는 최단 횟수만큼 더해줌
                
if __name__ == "__main__":
    n, k = map(int, input().split())
    graph = [INF] * 100001
    cnt = [0] * 100001
    graph[n] = 0
    cnt[n] = 1
    bfs(n)
    print(graph[k])
    print(cnt[k])


