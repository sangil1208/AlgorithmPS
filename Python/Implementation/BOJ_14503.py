'''
1. 입력이 북, 동, 남, 서 순서로 0, 1, 2, 3으로 주어지는데, 왼쪽 방향 순서대로 탐색하려면
서, 남, 동 북 순서대로 탐색해야함. 따라서 반복 시 다음 방향 선택을 위해 d=(d+3)%4적용
이는 만약 0:북이었다면, 3%4 = 3이므로 다음이 서쪽이 되고, 그 다음은 6%4=2이므로 남쪽이 되고...
이와같이 왼쪽으로 탐색이 가능하다.
2. 왼쪽방향으로 탐색하면서, 청소가 안된 곳을 발견하면 청소를 수행하고, 다시 그곳부터 왼쪽방향으로 탐색 수행
3. 청소가 안된 곳을 모든 4개의 방향에서 발견하지 못했다면, 한칸 후진하고, 후진한 칸이 벽(1)이면 종료한다.
4. 청소가 안된 곳을 모든 4개의 방향에서 발견하지 못했지만, 한칸 후진한 곳이 벽이 아니라면 다시 후진한 위치에서
왼쪽 방향으로 탐색을 수행한다.
'''
        
n, m = map(int, input().split())

r, c, d = map(int, input().split())

graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))

dir = [(-1, 0), (0, 1), (1, 0), (0, -1)]
graph[r][c] = 2
result = 1

while True:
    flag = 0
    for _ in range(4):
        d = (d+3)%4
        nx = r + dir[d][0]
        ny = c + dir[d][1]
        if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == 0:
            if graph[nx][ny] == 0:
                graph[nx][ny] = 2
                result += 1
                r = nx
                c = ny
                flag = 1
                break
    
    if flag != 1:
        if graph[r-dir[d][0]][c-dir[d][1]] == 1:
            break
        else:
            r = r-dir[d][0]
            c = c-dir[d][1]
            
print(result)