def rec (now):
	ret = 1
	for i in range(1,n+1):
		ret *= (now*2)+1-i
		ret //= i
	ret //= now+1
	return ret
	
n=int(input())
print(rec(n+1))