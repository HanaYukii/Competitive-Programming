t = int(input())
for _ in range(t):
    a,b,c = map(int,input().split())
    x = a + b
    print(x//c,end=".")
    x = x % c
    for i in range(50):
        x = x * 10;
        print(x//c,end="")
        x = x % c
    print("")

