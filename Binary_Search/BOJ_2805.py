# 0부터 나무 길이 최대값 까지의 범위를 이진 탐색하며 절단기 높이의 최대값을 구한다.
n, m = map(int, input().split())

trees = list(map(int, input().split()))

end = max(trees)
start = 0
result = 0

while(start <= end):
    sum = 0
    mid = (start + end) // 2
    for tree in trees:
        if tree > mid:
            sum += tree - mid
    if sum >= m:
        result = mid
        start = mid + 1
    # sum이 m보다 크면 sum을 줄이려는 시도 한다.(높이의 최댓값을 구한다는 의미는 sum의 최소값을 구하는 것)
    # sum을 줄이려면 mid가 커져야 하므로 start = mid + 1을 해준다.
    else:
        end = mid - 1

print(result)
