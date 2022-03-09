import sys
input = sys.stdin.readline

n = int(input())
num = []
for _ in range(n):
    num.append(int(input()))

# 산술평균
avg = sum(num)/len(num)
print(round(avg))

num.sort()
# 중앙값
if len(num)%2 == 0: # 개수가 짝수
    print(num[len(num)//2] + num[len(num)//2-1])
else:
    print(num[len(num)//2])
    
# 최빈값 -> 계수정렬 변형해서 음수도 처리하도록.
# 전체 입력 정수 범위보다 크게 count 리스트 선언해서 음수일 경우 -2 곱한 값에 count수행
count = [0] * 8001
for i in range(len(num)):
    if num[i] < 0 :
        count[(-1)*(num[i]+(-4000))] += 1
    else:
        count[num[i]] += 1

index_list = []
max_count = max(count)
for i in range(len(count)):
    if count[i] == max_count:
        if i >= 4001:
            i = (i-4000) * (-1)
        index_list.append(i)

index_list.sort()

if len(index_list) == 1:
    if index_list[0] >= 4001:
        print((index_list[0]-4000)*(-1))
    else:
        print(index_list[0])
else:
    if index_list[1] >= 4001:
        print((index_list[1]-4000)*(-1))
    else:
        print(index_list[1])
# 범위
print(max(num) - min(num))