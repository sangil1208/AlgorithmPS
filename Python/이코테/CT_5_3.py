import time

N, M = map(int, input().split())
graph = []
moves = [(-1,0), (1,0), (0,-1),(0,1)]

for i in range(N):
    graph.append(list(map(int,input())))

start = time.time()    

def dfs(x,y,graph):

    graph[x][y] = 1
    move_cnt = 0
    for move in moves:
        x_temp = x+move[0]
        y_temp = y+move[1]
        if (0<=x_temp and x_temp<N) and (0<=y_temp and y_temp<M):
            if graph[x_temp][y_temp] == 0:
                dfs(x_temp, y_temp, graph)
        else:
            move_cnt+=1
    if move_cnt == 4:
        return
                
res = 0

for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            dfs(i,j,graph)
            res += 1
        
print(res)
end = time.time()
print(abs(start-end))
