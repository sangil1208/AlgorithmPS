N = int(input())
stock = list(map(int, input().split()))
M = int(input())
target  = list(map(int, input().split()))

def bin_search(array, target, start ,end):
    while start <= end:
        mid = (start+end)//2
        if target == array[mid]:
            return True
        elif target < array[mid]:
            end = mid-1
        else:
            start = mid+1
    
    return False

for i in target:
    if bin_search(stock, i, 0, N-1) == True:
        print("yes", end=" ")
    else:
        print("no", end=" ")