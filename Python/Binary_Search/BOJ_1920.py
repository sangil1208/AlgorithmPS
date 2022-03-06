import sys


def binary_search(array, target, start, end):
    if start > end:
        print(0)
        return None
    mid = (start + end)//2
    if array[mid] == target:
        print(1)
        return None
    elif array[mid] > target:
        return binary_search(array, target, start, mid - 1)
    else:
        return binary_search(array, target, mid+1, end)


n = int(sys.stdin.readline())
# a안에 b가 존재하는지 확인 위해 a에 값 저장
a = list(map(int, sys.stdin.readline().split()))
# 이진 탐색은 리스트내 원소가 정렬되어있는 상태에서 사용 가능하므로 a를 정렬시켜준다.
a.sort()

m = int(sys.stdin.readline())
# 존재하는지 여부를 확인할 수를 b에 저장
b = list(map(int, sys.stdin.readline().split()))

# a리스트에서 b의 원소가 있는지 하나씩 이진탐색 한다.
for target in b:
    binary_search(a, target, 0, n-1)



