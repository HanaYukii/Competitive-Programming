[n,s] = map(int,input().split())
dic = {}
for i in range(n):
    a, b = input().split()
    dic[int(b)] = a
ans = []
for i in sorted(dic,reverse=True):
    if i > s:
        continue
    s -= i
    ans.append(dic[i])
if s != 0:
    print(0)
else:
    print(len(ans))
    for i in ans:
        print(i)
