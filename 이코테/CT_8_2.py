N = int(input())

d = [0]*30001

d[1] = 0
d[2] = 1

for i in range(3, N+1):
    if i%5==0:
        d[i] = min(d[i//5]+1, d[i-1]+1)
        i = i//5
    elif i%3 == 0 :
        d[i] = min(d[i//3]+1, d[i-1]+1)
        i = i//3
    elif i%2 == 0 :
        d[i] = min(d[i//2]+1, d[i-1]+1)
        i = i//2
    else:
        d[i] = d[i-1] + 1
        i = i-1

print(d[27])

'''
위와 같은 풀이방식으로 27은 구할 수 있지만,
6의 배수의 경우를 고려해주지 않음. 6의 배수의 경우는 2로 나누는 것과 3으로 나누는 것 중 최소를 택해야 함.
2로 나눈거, 3으로 나눈거, 1뺀거 3경우 중에서 최소를 구해야함
'''