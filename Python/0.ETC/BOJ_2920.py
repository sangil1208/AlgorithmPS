import sys
a = list(map(int, input().split()))
cnt = 1

if a[0]<a[1]:
    for i in range(1,len(a)-1):
        if a[i]<a[i+1]:
            cnt += 1
        else:
            print('mixed')
            break

if cnt==7:
    print('ascending')
    sys.exit()
            
if a[0]>a[1]:
    for i in range(1, len(a)-1):
        if a[i]>a[i+1]:
            cnt += 1
        else:
            print('mixed')
            break
    
if cnt==7:
    print('descending')

        