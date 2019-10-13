import math
n = int(input())
c = list(map(int,input().split()))
g = 0
for i in c:
	g = math.gcd(g,i)
sq = (int)math.sqrt(g)
ans = 0
for i in range(1,sq+1):
	if(g%i!=0):
		continue
	elif i==sq:
		ans += 1
	else:
		ans += 2
print(ans)