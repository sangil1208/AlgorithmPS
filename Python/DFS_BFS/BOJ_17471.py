'''
1. 모든 노드의 조합 구함
2. 조합에 대해 양쪽이 모두 connected 인지 확인
3. connected라면 각각 합계 구해서 빼줌
'''

from itertools import combinations
from collections import deque
import math

def is_connected(target): # 조합으로 구한 리스트 원소들이 connected인지 확인
    if len(target) == 1: # 노드 하나일 경우 connected로 판정하기 위함
        return True
    q = deque([])
    q.append(target[0])
    while q:
        v = q.popleft()
        for i in graph[v-1]:
            if i not in target: # target 리스트 안에 없는 곳으로는 탐색 수행하지 않음(큐에 append 안함)
                continue
            if not visited[i-1]:
                q.append(i)
                visited[i-1] = True
    
    for t in target:
        if visited[t-1] == False:
            return False
    
    return True
        
n = int(input())

nums = list(map(int, input().split()))

nodes = [i for i in range(1, n+1)]
graph = [[] for _ in range(n)]
visited = [False for _ in range(n)]
result = math.inf

for i in range(n):
    temp = list(map(int, input().split()))
    temp.pop(0)
    for t in temp:
        graph[i].append(t)
        

for i in range(1, n//2+1): # 모든 조합 경우의수를 계산, A,B로 나눠서 각 A,B가 둘다 connected이면 각 node의 합을 계산 후 차이 구함
    comb = list(combinations(nodes, i))
    for A in comb:
        B = list(set(nodes)-set(A))
        A = list(A)
        visited = [False for _ in range(n)]
        if is_connected(A) and is_connected(B):
            sum_a = 0
            sum_b = 0
            for j in A:
                sum_a += nums[j-1]
            for j in B:
                sum_b += nums[j-1]
            
            if abs(sum_a - sum_b) < result:
                result = abs(sum_a - sum_b)
                
if result == math.inf:
    print(-1)
else:
    print(result)
