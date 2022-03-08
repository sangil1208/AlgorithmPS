# import sys
# input = sys.stdin.readline

# n, m = map(int, input().split())

# graph = []

# for _ in range(n):
#     graph.append(list(input().rstrip()))
    
# print(graph)
                 
while True:
    str = input().rstrip()
    if str == ".":
        break
    
    stack = []
    br = ['(', ')', '[', ']']
    
    for i in range(len(str)):
        for b in br:
            if str[i] == b:
                stack.append(b)
                
    print(stack)
    
    for i in range(len(stack)-2):
        if stack[i] == '(' and stack[i+1] == ')':
            stack.pop(i)
            stack.pop(i)
            
        if stack[i] == '[' and stack[i+1] == ']':
            stack.pop(i)
            stack.pop(i)

    print(stack)