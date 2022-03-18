'''
삼각형의 맨 밑 값들에 해당 값까지 오기 위한 최댓값들을 저장한다.
맨 왼쪽, 오른쪽 숫자는 바로 자기 위 숫자 더하고,
다른 숫자들은 왼쪽 위, 오른쪽 위를 비교해 큰 값을 더한다.
-> 이 과정을 거치면 삼각형 맨 밑에 해당 값까지 오기 위한 최댓값들이 저장되고, 이 중 max를 출력한다.

7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

=>

7
10 15
18 16 15
20 25 20 19
24 30 27 26 24
'''


n = int(input())

graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))


for i in range(1, n):
    for j in range(i+1):
        if j == 0:
            graph[i][j] = graph[i][j] + graph[i-1][j]
        elif j == i:
            graph[i][j] = graph[i][j] + graph[i-1][j-1]
        else:
            graph[i][j] = graph[i][j] + max(graph[i-1][j], graph[i-1][j-1])
            
print(max(graph[n-1]))