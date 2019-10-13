t = int(input())
for _ in range(t):
	n = int(input())
	c = list(map(int,input().split()))
	idx = 0
	f = 0
	f2 = 0
	for i in range(n):
		if(c[i]==1):
			idx = i
			break

	for i in range(n):
		if(c[(idx+i)%n]!=i+1):
			f = 1
		if(c[idx-i]!=i+1):
			f2 = 1
	if f == 1 and f2 ==1:
		print('NO')
	else:
		print('YES')