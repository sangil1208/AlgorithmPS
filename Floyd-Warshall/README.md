# Floyd-Warshall Algorithm  
- 다익스트라 알고리즘은 한 지점에서 다른 특정 지점까지의 최단 경로를 구해야 하는 경우에 사용한다.  
  
- 다익스트라 알고리즘은 단계마다 최단 거리를 가지는 노드를 하나씩 반복적으로 선택한다. 그리고 해당 노드를
거쳐 가는 경로를 확인하며, 최단거리 테이블을 갱신하는 방식으로 동작한다.  
- 다익스트라 알고리즘은 출발 노드가 1개이므로, 다른 모든 노드까지의 최단 거리 저장을 위해 1차원 리스트 이용 
- 다익스트라 알고리즘은 그리디 알고리즘이다.
  
  
* * *
* * *

- 플로이드 워셜 알고리즘은 모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구하는 경우에 사용한다.  
  
- 플로이드 워셜 알고리즘도 단계마다 거쳐가는 노드를 기분으로 알고리즘을 수행하지만, 매번 방문하지 않은
노드 중에서 최단 거리를 갖는 노드를 찾을 필요가 없다.  
- 노드의 개수가 N개일때, 알고리즘상 N번의 단계 수행하며, 단계마다 O(N^2)의 연산을 통해 현재 노드를 거쳐가는
모든 경로를 고려한다. 따라서 플로이드 워셜 알고리즘의 총 시간 복잡도는 O(N^3) 이다.  
- 모든 노드에 대해 다른 모든 노드로 가는 최단거리를 저장하기 위해 2차원 리스트를 이용한다.
N번에 단계에 대해 매번 2차원 리스트를 처리하므로 O(N^2)의 시간이 소요된다.  
- 현재 확인하고 있는 노드를 제외하고, N-1개의 노드 중에서 서로 다른 노드 (A,B)쌍을 선택한다.
이후에 A -> X -> B 로 가는 비용을 확인한 후 최단거리를 갱신한다. 단계마다 P(N-1, 2)개의 쌍을 확인한다.
따라서 시간 복잡도가 O(P(N-1, 2)) = O(N^2) 이다.  
- X번의 단계에 대한 점화식  
*<center>####$$D_{AB} = min(D_{AB}, D_{AX}+D_{XB})$$</center>*

## Base Code  
  
```python
import sys
input = sys.stdin.readline

INF = int(1e9)

n, m = map(int, input().split())
graph = [[INF]*(n+1) for _ in range(n+1)]

# 자기 자신에서 자기 자신으로 가는 비용 0으로 초기화
for a in range(1, n+1):
    for b in range(1, n+1):
        if a == b:
            graph[a][b] = 0

# 각 간선에 대한 정보 입력
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = c
    
# FW 알고리즘 수행
for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])

# 결과 출력
for a in range(1, n+1):
    for b in range(1, n+1):
        if graph[a][b] = INF:
            print("INF", end=' ')
        else:
            print(graph[a][b], end=' ')
    print()

```


