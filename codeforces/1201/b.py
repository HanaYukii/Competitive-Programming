n = int(input())
a = sorted(map(int,input(),split()))
s = sum(a)
m = max(a)
if s%2:
	print('NO')
else if m*2 > s:
	print('NO')
else:
	print('YES')