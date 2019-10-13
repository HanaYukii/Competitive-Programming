t = int(input())
for _ in range(t):
	a,b,c = map(int,input().split())
	if b*2<=c:
		print(a*b)
	else:
		print(a//2*c+b*(a&1))

