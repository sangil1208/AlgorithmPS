'''
0. 뱀의 몸체는 3으로, 사과는 2로 표시
1. 오른쪽 회전, 왼쪽 회전을 위한 수식 설정. 동 남 서 북 순서로 dir 리스트를 만들어놓고, 오른쪽 회전은 (cur_dir+1)%4, 왼쪽 회전은 (cur_dir+3)%4 으로 구할 수 있음
2. 뱀의 길이가 늘어날 때 마다 snake리스트에 좌표를 append 시킴. 0을 만나서 꼬리를 잘라야 하는 경우 snake리스트의 첫 요소를 삭제함.
3. 한칸씩 이동하면서 time을 1씩 증가시키고, 입력된 (시간 ,회전) 에 일치하는 시간이 된 경우 회전을 수행
4. 입력된 그래프의 범위를 벗어나거나, 자신의 몸체와 (값이 3인 곳과) 부딪치면 종료, 종료까지 걸린 시간 출력
'''


n = int(input())
k = int(input())

dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
graph = [[0]*n for _ in range(n)]

            
# start point            
x, y = 0, 0
snake = []
graph[x][y] = 3
snake.append((x,y))

# 동 남 서 북 순서
cur_dir = 0

for _ in range(k):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 2
    
l = int(input())
dir_change = []

for _ in range(l):
    temp = input().split()
    dir_change.append((temp[0], temp[1]))

time = 0


while True:
    time += 1 
    x = x + dir[cur_dir][0]
    y = y + dir[cur_dir][1]
    if 0>x or x>=n or 0>y or y>=n or graph[x][y] == 3:
        break
    
    if graph[x][y] == 2:
        graph[x][y] = 3
        snake.append((x,y))

        
    if graph[x][y] == 0:
        graph[x][y] = 3
        snake.append((x,y))
        tail_x, tail_y = snake[0]
        del snake[0]
        graph[tail_x][tail_y] = 0
            
    for i in range(l):
        if int(dir_change[i][0]) == time:
            if dir_change[i][1] == 'L':
                cur_dir = (cur_dir+3)%4
            else:
                cur_dir = (cur_dir+1)%4

print(time)
