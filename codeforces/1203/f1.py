n,r = map(int,input().split())
pl = []
mi = []
for _ in range(n):
	a,b = map(int,input().split())
	if b >= 0:
		pl.append((a,b))
	else:
		mi.append((a,b))
pl.sort()
mi.sort(key=lambda t:t[0]+t[1])
mi.reverse()
for i,j in pl:
	if(r < i):
		print('NO')
		exit(0)
	else:
		r += j
for i,j in mi:
	if(r<i):
		print('NO')
		exit(0)
	else:
		r += j
if r < 0:
	print('NO')
else:
	print('YES')
