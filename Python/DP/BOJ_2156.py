'''
DP문제

현재 index에서, 바로 이전 index의 포도주를 마시기로 선택한 경우, index-3의 dp table의 값 + 현재 + 이전 포도주 양을 더한다.
현재 index에서, 바로 이전 index의 포도주를 마시지 않기로 한 경우, index-2의 dp table의 값 + 현재 포도주 양을 더한다
(**현재 index의 포토주를 마시지 않는 경우도 고려해야 한다.)

두 가지 주의사항이 있다.
1. 먼저, dp table은 3번째부터 갱신하도록 짰으므로 첫번째와 두번째에 대해 따로 출력 처리를 해준다.
2. 현재 index의 포도주를 마시지 않기로 선택한 경우도 고려해야한다.
'''

n = int(input())

nums = []

d = [0]*(n)

for _ in range(n):
    nums.append(int(input()))
    
if n == 1:
    print(nums[0])
elif n == 2:
    print(nums[0]+nums[1])
else:
    d[0] = nums[0]
    d[1] = nums[0] + nums[1]
    d[2] = max(nums[0]+nums[1], nums[1]+nums[2], nums[0]+nums[2])

    for i in range(3, n):
        d[i] = max(d[i-1], nums[i-1] + nums[i] + d[i-3], d[i-2] + nums[i])
        
    print(max(d))