#걸리는 시간이 짧은 순으로 리스트를 정렬한 후,
#누적 합계를 계산한다. 누적시간은 이전 사람이 인출하는데 걸린 시간의 합 + 현재 사람이 인출하는데 걸리는 시간으로 구한다

n = int(input())
a = list(map(int, input().split()))

a.sort()

temp = 0
result = 0

for i in a:
    temp += i
    result += temp
    
print(result)
    