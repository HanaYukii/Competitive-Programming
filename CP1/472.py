while 1:
    try:
        x = (int(_) for _ in input().strip().split())
        x=list(x)
        x.sort()
        if len(x)==1:
            if (int(x[0]**0.5))**2==x[0]:
                print('Yes')
                print(int(x[0]**0.5))
            else:
                print('No')
        elif len(x)==4:
            if (int(x[0]**0.5))**2==x[0] and (int(x[3]**0.5))**2==x[3] and x[2]==x[1] and x[2]*x[1]==x[0]*x[3]:
                print('Yes')
                print("%d %d"%(int(x[0]**0.5),int(x[3]**0.5)))
            else:
                print('No')
        elif len(x)==9:
            ans=[]
            ans.append(int(x[0]**0.5))
            ans.append(x[1]//ans[0])
            ans.append(int(x[8]**0.5))
            cmp=[]
            for _ in ans:
                for __ in ans:
                    cmp.append(_*__)
            cmp.sort()
            f=0
            for _,__ in zip(x,cmp):
                if _!=__:
                    f=1
                    break
            if f==0:
                print('Yes')
                print("%d %d %d"%(ans[0],ans[1],ans[2]))
            else:
                print('No')
        elif len(x)==16:
            ans=[]
            ans.append(int(x[0]**0.5))
            ans.append(x[1]//ans[0])
            ans.append(int(x[15]**0.5))
            ans.append(x[14]//ans[2])
            (ans[3],ans[2])=(ans[2],ans[3])
            cmp=[]
            for _ in ans:
                for __ in ans:
                    cmp.append(_*__)
            cmp.sort()
            f=0
            for _,__ in zip(x,cmp):
                if _!=__:
                    f=1
                    break
            if f==0:
                print('Yes')
                print("%d %d %d %d"%(ans[0],ans[1],ans[2],ans[3]))
            else:
                print('No')
        elif len(x)==25:
            ans=[]
            ans.append(int(x[0]**0.5))
            ans.append(x[1]//ans[0])
            ans.append(int(x[24]**0.5))
            ans.append(x[23]//ans[2])
            ans.append(int(sum(x)**0.5)-sum(ans))
            (ans[4],ans[2])=(ans[2],ans[4])
            cmp=[]
            for _ in ans:
                for __ in ans:
                    cmp.append(_*__)
            cmp.sort()
            f=0
            for _,__ in zip(x,cmp):
                if _!=__:
                    f=1
                    break
            if f==0:
                print('Yes')
                print("%d %d %d %d %d"%(ans[0],ans[1],ans[2],ans[3],ans[4]))
            else:
                print('No')
    except EOFError:
        break
