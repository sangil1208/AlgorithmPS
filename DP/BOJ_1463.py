# 시간 제한이 있고 매우 큰 정수가 입력되므로 dp로 푸는 문제
import sys
input = sys.stdin.readline

N = int(input())

d = [0]*1000001  # DP테이블 초기화

for i in range(2, N+1):
    # 현재 수에서 1빼는 경우로 초기화 후 다음 조건들 비교 (작은수로 나누는것부터)
    d[i] = d[i-1] + 1
    # 현재 수가 2로 나누어 지는 경우
    if i % 2 == 0:
        d[i] = min(d[i], d[i//2]+1)
    # 현재 수가 3으로 나누어 지는 경우
    if i % 3 == 0:
        d[i] = min(d[i], d[i//3]+1)

print(d[N])

