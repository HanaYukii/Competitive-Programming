n = int(input())
c = sorted(list(map(int,input().split())))
last = 0
ans = 0
for i in (c):
	if(last>i):
		continue
	elif(last<i-1):
		last = i-1
		ans++
	elif(last==i-1):
		last = i
		ans++
	else:
		last = i+1
		ans++
print(ans)
