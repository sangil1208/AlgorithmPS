'''
벽 3개를 반드시 세워야 한다.
0 중에서 3개씩 골라 벽을 세우고, 이후 2인 곳부터 bfs를 수행한다.
모든 2인 곳에서 bfs 수행 후, 남은 0의 개수를 센다.
모든 조합의 경우의 수에서 2인 곳들에서 bfs를 수행한 후 남은 0의 개수 중 최댓값을 출력한다.

이 과정에서 0 중에서 3개를 고르기 위해 조합을 구현한다.
파이썬의 itertools를 사용하거나, 조합 함수를 구현하는 방법이 있다.
하지만 삼성 sw 역량테스트에서 itertools를 사용하지 못하게 한 경우가 있어 구현하는 방법으로 풀었다.
'''



import sys
import copy
from collections import deque

input = sys.stdin.readline
moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]
def dfs_comb(lst,n):
    ret = []
    idx = [i for i in range(len(lst))]

    stack  = []
    for i in idx[:len(lst)-n+1]:
        stack.append([i])

    while len(stack)!=0:
        cur = stack.pop()

        for i in range(cur[-1]+1,len(lst)-n+1+len(cur)):
            temp=cur+[i]
            if len(temp)==n:
                element = []
                for i in temp:
                    element.append(lst[i])
                ret.append(element)
            else:
                stack.append(temp)
    return ret

def bfs(temp_graph, x, y):
    queue = deque([(x, y)])
    while queue:
        v = queue.popleft()
        for move in moves:
            dx = v[0]+move[0]
            dy = v[1]+move[1]
            if 0 <= dx <n and 0<= dy < m:
                if temp_graph[dx][dy] == 0:
                    temp_graph[dx][dy] = 2
                    queue.append((dx, dy))
    
if __name__ == "__main__" :
                
    n, m = map(int, input().split())

    graph = []
    zeros = []
    viruses = []
    cnt_list = []

    for _ in range(n):
        graph.append(list(map(int, input().split())))
        
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                zeros.append((i, j))
            if graph[i][j] == 2:
                viruses.append((i, j))

    combs = dfs_comb(zeros, 3)

    for comb in combs:
        cnt = 0
        temp_graph = copy.deepcopy(graph)
        a = comb[0]
        b = comb[1]
        c = comb[2]
        temp_graph[a[0]][a[1]] = 1
        temp_graph[b[0]][b[1]] = 1
        temp_graph[c[0]][c[1]] = 1
        
        for virus in viruses:
            bfs(temp_graph, virus[0], virus[1])
        
        for i in range(n):
            for j in range(m):
                if temp_graph[i][j] == 0:
                    cnt += 1
        
        cnt_list.append(cnt)
    
    print(max(cnt_list))