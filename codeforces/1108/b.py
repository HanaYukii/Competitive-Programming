n = int(input())
c = sorted(list(map(int,input().split())))
b = c[-1]
last = 0
for i in range(len(c)):
	if(b%c[i]==0 and c[i]!=c[i-1]):
		continue
	else:
		last = c[i]
print(last,end=" ")
print(b)