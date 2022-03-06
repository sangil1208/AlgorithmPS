# 끝나는 시간으로 오름차순 정렬, 하지만 끝나는 시간이 동일한 경우 시작 시간이 빠른 것이 앞에 오도록 하기 위해서
# 시작 시간으로 정렬 후 끝나는 시간으로 정렬한다.
# 이후, 시작 시간이 이전 회의의 끝나는 시간보다 크거나 같은 경우만 선택해서 횟수를 증가시킨다.

# 빨리 끝나는 회의부터 배정하면, 남아있는 시간이 길게 되므로 강의를 많이 배정할 확률이 올라간다
# 끝나는 시간이 같은 회의는 시작 시간이 빠른것을 먼저 고르도록 한다.

# 만약 (1,4) 와 (4,4) 가 있는데 (4,4) 가 먼저 정렬되어 있다면 (1,4) 가 선택되지 않아 최대 갯수가 안나온다.
# 따라서 (1,4) 가 (4,4) 앞에 오도록 빨리 시작하는 기준으로 정렬 후에 빨리 끝나는 기준으로 오름차순 정렬하면 된다.abs()

N = int(input())
time = []

for i in range(N):
    start, end = map(int, input().split())
    time.append((start, end))

time.sort(key=lambda x: x[0])
time.sort(key=lambda x: x[1])

finish = time[0][1]
cnt = 1

for i in range(1, N):
    if time[i][0] >= finish:
        cnt += 1
        finish = time[i][1]

print(cnt)
