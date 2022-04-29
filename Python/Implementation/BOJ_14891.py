from collections import deque

a = deque((map(int, input())))
b = deque((map(int, input())))
c = deque((map(int, input())))
d = deque((map(int, input())))

k = int(input()) 
    
def n_1(f):
    if a[2] != b[6]:
        if b[2] != c[6]:
            if c[2] != d[6]:
                a.rotate(f)
                b.rotate(-f)
                c.rotate(f)
                d.rotate(-f)
            else:
                a.rotate(f)
                b.rotate(-f)
                c.rotate(f)
        else:
            a.rotate(f)
            b.rotate(-f)
    else:
        a.rotate(f)
            
def n_4(f):
    if d[6] != c[2]:
        if c[6] != b[2]:
            if b[6] != a[2]:
                d.rotate(f)
                c.rotate(-f)
                b.rotate(f)
                a.rotate(-f)
            else:
                d.rotate(f)
                c.rotate(-f)
                b.rotate(f)
        else:
            d.rotate(f)
            c.rotate(-f)
    else:
        d.rotate(f)

def n_2(f):
    if a[2] != b[6] and b[2] == c[6]: #1번만 회전
        b.rotate(f)
        a.rotate(-f)
        
    elif a[2] == b[6] and b[2] != c[6]: #3번만 회전
        if c[2] != d[6]:
            b.rotate(f)
            c.rotate(-f)
            d.rotate(f)
        else:
            b.rotate(f)
            c.rotate(-f)
        
    elif a[2] != b[6] and b[2] != c[6]: # 둘다 회전
        if c[2] != d[6]:
            b.rotate(f)
            a.rotate(-f)
            c.rotate(-f)
            d.rotate(f)
        else:
            b.rotate(f)
            a.rotate(-f)
            c.rotate(-f)
    else:
        b.rotate(f)
        
def n_3(f):
    if c[6] == b[2] and c[2] != d[6]: 
        c.rotate(f)
        d.rotate(-f)
    
    elif c[2] == d[6] and c[6] != b[2]:
        if b[6] != a[2]:
            c.rotate(f)
            b.rotate(-f)
            a.rotate(f)
        else:
            c.rotate(f)
            b.rotate(-f)
            
    elif c[2] != d[6] and c[6] != b[2]:
        if b[6] != a[2]:
            c.rotate(f)
            b.rotate(-f)
            d.rotate(-f)
            a.rotate(f)
        else:
            c.rotate(f)
            b.rotate(-f)
            d.rotate(-f)
    else:
        c.rotate(f)

for _ in range(k):
    n, f = map(int, input().split())
    
    if n == 1:
        n_1(f)
    if n == 2:
        n_2(f)
    if n == 3:
        n_3(f)
    if n == 4:
        n_4(f)
        
print(a[0]*1 + b[0]*2 + c[0]*4 + d[0]*8)