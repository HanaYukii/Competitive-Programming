t = int(input()):
for _ in range(t):
	n = int(input())
	c = sorted(list(map(int,input().split())))
	tar = c[0]*c[-1]
	f = 0
	for i in range(n):
		idx = 2*i
		if c[idx] != c[idx+1]:
			f = 1
		if(c[-idx]!= c[-idx-1]):
			f = 1
		if(c[idx]*c[-idx]!=tar):
			f = 1
	if f == 1:
		print('NO')
	else
		print('YES')
