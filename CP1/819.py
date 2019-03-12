try:
    while True:
        ans = 0
        x = (int(_) for _ in input().strip().split())
        for _ in x:
            ans += _
        print(ans)
except:
    pass