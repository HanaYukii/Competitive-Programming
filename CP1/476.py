while 1:
    try:
        x = (int(_) for _ in input().strip().split())
        x=list(x)
        ans=2
        for i in range(len(x)-2,-1,-1):
            if ans<=x[i]:
                ans=min(ans*2,x[i])
            else:
                if ans-(x[i]+1)//2>x[i]:
                    ans=ans-(x[i]+1)//2
                else:
                    ans=x[i]+1
        print(ans)    
    except EOFError:
        break
