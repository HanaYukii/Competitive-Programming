n,m = map(int,input.split())
a = zip(*(input() for _ in range(n)))
t = 0
for x,y in zip (a,map(int,input(),split())):
	t += max(x.count(c) for c in 'ABCDE')*y
print(t)