'''
n개의 수를 원형 큐로 저장하기 위해 double ended queue인 deque이용.
k개씩 deque의 왼쪽부터 제거하고, 앞에서 k-1개는 다시 오른쪽에 append,
k번째 제거한 요소는 결과 리스트에 추가한다.
'''


from collections import deque

n, k = map(int, input().split())

q = deque()

for i in range(1, n+1):
    q.append(i)

result = []

while q:
    for i in range(k):
        temp = q.popleft()
        if i==k-1:
            result.append(temp)
        else:
            q.append(temp)

tmp = str(result)
tmp = tmp[1:len(tmp)-1]
print('<' + tmp + '>')