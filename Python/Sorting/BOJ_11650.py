# 2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.
# 튜플 형태로 입력 받은 후, y좌표 기준으로 정렬 후 x좌표 기준으로 정렬

N = int(input())
points = []

for _ in range(N):
    a, b = map(int, input().split())
    points.append((a,b))
    
points.sort(key=lambda x: x[1])
points.sort(key=lambda x: x[0])

for point in points:
    print(point[0], point[1])