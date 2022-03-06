'''
정렬 라이브러리를 사용해서 풀 수 있는 간단한 문제인데, 입력을 map을 이용하여 int로 받아줘야 했다.
int로 받지 않으면, 숫자가 문자로 인식되어 정렬시 수가 아닌 문자 기준 정렬이 되어 틀릴 수 있다.
또한, 정렬 시 lambda를 사용할 때, 두 개의 기준을 차례로 정할 수 있다.
a.sort(key = lambda x: (x[1], x[0]))
위와 같이 lambda를 설정하면, 두 번째 요소를 기준으로 먼저 정렬하고, 두 번째 요소가 같으면
첫 번째 요소를 다음 정렬기준으로 삼는다.
'''

N = int(input())
a = []

for i in range(N):
    a.append(tuple(map(int,input().split())))

a.sort(key = lambda x: (x[1], x[0]))

for i in a:
    print(i[0], i[1])