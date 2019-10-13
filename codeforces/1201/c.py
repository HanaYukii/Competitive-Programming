n,k = map(int,input().split())
a = sorted(map(int,input().split()))[n//2:]
i = 0
s = 0
while i < len(a):
	s += a[i]
	if a[i]*(i+1) - s > k:
		break
	i += 1
k -= a[i-1]*i-sum(a[:i])
print(a[i-1]+k//i)