'''
배열의 이전 값들과 비교하면서, 현재 값이 이전 값보다 크다면 현재 값의 dp table 1 증가시킨다.
dp table에서 이전 값들의 최대값에 1을 증가시키기 위해 d[j]+1 > d[i] 인 경우에만 d[i] 값 갱신시키도록 한다.
또한 j 반복문 안 if문에 해당하는 조건을 한번도 만족시키지 못한 경우는 모든 이전 값들보다 현재 값이 작다는 것이므로
dp table에 1을 저장해 준다.
'''

n = int(input())
arr = list(map(int, input().split()))

d = [0]*1001

d[0] = 1

for i in range(1, n):
    flag = 0
    for j in range(i-1, -1, -1):
        if arr[i] > arr[j] and d[j]+1>d[i]:
            d[i] = d[j]+1
            flag = 1
    if flag == 0:
        d[i] = 1
        
print(max(d))