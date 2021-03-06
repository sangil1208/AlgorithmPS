'''
두 번째 집부터 시작해서, 
해당 집을 각각 R, G, B중 하나로 선택했을때
이전 집의 색으로 가능한 나머지 2개중 최솟값과
현재 집에서 선택한 색의 값을 더해서 현재 집을 각각 R, G, B로 칠할때
필요한 값의 최솟값을 [0], [1], [2] 요소에 저장한다.

6 40 83
49 60 57
13 89 99

예를 들어 위와 같은 경우, 두번째 집부터 시작해서
두번째 집을 R로 칠한다면 이전 집인 첫번째 집의 40, 83중 최솟값과 49를 더해 [1][0]에 저장한다.
G로 칠한다면 첫번째 집의 6, 83 중 최솟값인 6 과 60을 더해 [1][1]에 저장한다. 
[1][0] 에 저장된 값은 두 번째 집을 R로 칠하는 경우 드는 최소비용이고, 
[1][1]에 저장된 값은 두 번째 집을 G로 칠하는 경우 드는 최소 비용을 의미한다. 
'''

N = int(input())

RGB = []

for i in range(N):
    RGB.append(list(map(int, input().split())))

for i in range(1, N):
    RGB[i][0] = min(RGB[i-1][1], RGB[i-1][2]) + RGB[i][0]
    RGB[i][1] = min(RGB[i-1][0], RGB[i-1][2]) + RGB[i][1]
    RGB[i][2] = min(RGB[i-1][0], RGB[i-1][1]) + RGB[i][2]

print(min(RGB[N-1]))

# 시간 제한이 매우 짧고, 이전 계산 값들을 사용해 비교해야하므로 dp사용