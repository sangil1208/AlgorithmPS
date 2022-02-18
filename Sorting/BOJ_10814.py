'''
나이, 이름 데이터를 정렬하는 문제
나이순으로 정렬하고, 나이가 같다면 입력 순서대로 정렬
입력 순서대로 append하면 입력 순서 정렬은 완료되었으므로, 나이로만 정렬 수행해주면 됨.
나이, 이름에서 나이로 정렬 위해 lambda이용한 정렬 사용. 
lambda x:x[0]은 첫 번째 요소를 기준으로 정렬하는것을 의미한다.
'''

N = int(input())

array = []

for i in range(N):
    input_data = input().split()
    array.append((int(input_data[0]), input_data[1]))

array.sort(key = lambda x:x[0])

for i in range(N):
    print(array[i][0], end=" ")
    print(array[i][1])
    
