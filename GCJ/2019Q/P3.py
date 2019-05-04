import math
t=int(input())
for c in range(1,t+1):
    R=lambda:map(int,input().split())
    k,n=R()
    n+=1
    cont=[]
    num=[]
    tmp=[]
    cont = [int(i) for i in input().split()]
    for _ in range (0,n+5):
        num.append(0)
    for i in range (0,n):
        if cont[i]!=cont[i+1]:
            num[i+1]=math.gcd(cont[i],cont[i+1])
            for j in range (i+2,n):
                num[j]=cont[j-1]//num[j-1]
            for j in range (i,-1,-1):
                num[j]=cont[j]//num[j+1]
            break
                
		
    for i in range(0,n):
        tmp.append(num[i])
    tmp.sort()
    now = ord('A')
    d={tmp[0]:chr(now)}
    print("Case #",end="")
    print(c,end="")
    print(": ",end="")
    for i in range(1,n):
        if tmp[i]!=tmp[i-1]:
            now = now +1
            d[tmp[i]]=chr(now)
    for i in range(0,n):
        print(d[num[i]],end="")
    print()

