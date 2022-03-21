
'''
첫 알파벳 부터 시작해, 탐색하지 않은 알파벳으로만 가지치기를 하며 횟수를 1씩 증가시킨다.
다른 알파벳 발견 시, 바로 이전 분기로 돌아가서 다시 dfs를 수행하도록 한다.
이를 구현하기 위해 동일 branch에서 발견 못한 알파벳을 발견했을 시 발견 표시를 하고, 해당 지점에서 분기를 더 수행한다(dfs).
branch에서 다른 방향으로 분기할 것을 고려해서 발견 표시를 dfs수행 후 다시 미발견으로 표기한다.

dfs 이용한 아래 코드는 pypy3로 제출해야 통과, python3는 시간초과 발생했다.
'''



moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def dfs(graph, x, y, cnt):
    if cnt > max(cnt_list):
        cnt_list.append(cnt)
    for move in moves:
        dx = x + move[0]
        dy = y + move[1]
        if 0<=dx<R and 0<=dy<C and alp[ord(graph[dx][dy]) - 65] == 0:
            alp[ord(graph[dx][dy]) - 65] = 1
            dfs(graph, dx, dy, cnt+1)
            alp[ord(graph[dx][dy]) - 65] = 0
          
            
if __name__ == "__main__":
    R, C = map(int, input().split())
    graph = []
    cnt_list = []
    alp = [0]*26
    
    for _ in range(R):
        graph.append(list(input().rstrip()))
    
    alp[ord(graph[0][0]) - 65] = 1
    cnt_list.append(1)
    
    dfs(graph, 0, 0, 1)
    
    print(max(cnt_list))

