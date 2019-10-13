t = int(input())
for _ in range(t):
	a,b,c,d = map(int,input().split())
	if a < d:
		print(a,end=" ")
		print(d)
	else:
		print(b,end=" ")
		print(c)

