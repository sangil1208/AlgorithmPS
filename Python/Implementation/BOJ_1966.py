#1966
'''
파이썬 deque라이브러리를 이용해, 입력된 순서대로 번호를 부여해
(번호, 우선순위) 튜플을 큐에 삽입한다.
이후 하나씩 차례로 큐에서 꺼내면서 우선순위가 가장 높은 값인지 확인하고,
가장 높은 값이라면 꺼내면서 cnt 값을 1 증가, 가장 높은 값이 아니라면
cnt 증가시키지 않고 다시 큐의 맨 뒤에 넣는다.
이와 같은 방식을 적용할때, 꺼내진 튜플의 번호가 찾는 번호와 일치하다면 
cnt를 1 증가시키며 반복문을 빠져나가고, 최종 몇 번째로 큐에서 나왔는지 cnt에 결과 저장.

처음 제출 시 런타임에러(valueerror)가 발생했는데, 매 반복문마다 큐를 새로 초기화해주지 않아서 발생한 문제이다.
이 문제는 테스트케이스의 수를 입력받고, 그 수만큼 여러 테스트케이스가 입력될 수 있기 때문에
테스트 케이스마다 큐를 초기화하도록 구현해야 한다.
'''

from collections import deque

test_cases = int(input())

for i in range(test_cases):
    q = deque()
    N, M = map(int, input().split())
    arr = list(map(int, input().split()))

    cnt = 0
    for i in range(N):
        q.append((i, arr[i]))


    while True:
        max_q = max(arr)
        temp = q.popleft()
        
        if temp[0]==M and temp[1]==max_q:
            cnt+=1
            break
        if temp[1]!=max_q:
            q.append(temp)
        else:
            arr.remove(max_q)
            cnt+=1

    print(cnt)
        