n, m = map(int, input().split())
graph = []

dir = [(0,0), (0,-1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]
        
def water(inc_list):
    moves = [(1,1), (1,-1), (-1,1), (-1,-1)]
    cnt_list = []
    for i in inc_list:
        cnt = 0
        for move in moves:
            if 0 <= i[0]+move[0] < n and 0 <= i[1] + move[1] < n:
                if graph[i[0] + move[0]][i[1] + move[1]] != 0:
                    cnt += 1
        cnt_list.append(cnt)

    for i in range(len(inc_list)):
        graph[inc_list[i][0]][inc_list[i][1]] += int(cnt_list[i])
    

for _ in range(n):
    temp = list(map(int, input().split()))
    graph.append(temp)


cloud = [(n-1, 0), (n-1, 1), (n-2, 0), (n-2, 1)]

for _ in range(m):
    d, s = map(int, input().split())
    cloud_flag = [[0]*n for _ in range(n)]
    inc = []
    for i in range(len(cloud)):
        inc_x = (cloud[i][0]+dir[d][0]*s)%n
        inc_y = (cloud[i][1]+dir[d][1]*s)%n
        graph[inc_x][inc_y] += 1
        inc.append((inc_x, inc_y))
        
    for i in inc:
        cloud_flag[i[0]][i[1]] = 1
    
    cloud.clear()
    water(inc)
    
    for i in range(n):
        for j in range(n):
            if graph[i][j] >= 2 and cloud_flag[i][j] == 0:
                cloud.append((i,j))
                graph[i][j] -= 2
    

res = 0

for i in range(n):
    for j in range(n):
        res += graph[i][j]

print(res)  
    
