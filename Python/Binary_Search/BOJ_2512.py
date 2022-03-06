# 총 예산이 될 수 있는 범위가 매우 크므로 이진 탐색 이용
# 배정 가능한 예산의 합이 전체 예산보다 작을 경우


import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
M = int(input())
start = 0
end = max(a)
result = 0

if sum(a) <= M:
    print(max(a))

else:
    while start <= end:
        mid = (start + end)//2
        sum = 0
        for i in range(len(a)):
            if mid >= a[i]:
                sum += a[i]
            else:
                sum += mid
        if sum <= M:
            result = mid
            start = mid+1
        else:
            end = mid-1

    print(result)
