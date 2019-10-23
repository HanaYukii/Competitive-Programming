[n,m,k] = map(int,input().split())
g = max(0,(n-(m-1)*(k-1))//k);
ans = 0
while g <= n//k:
    rem = (n-g*k)%m
    ans = max(ans,(g*(2*n-(g+m)*k) + (m+1)*n + rem * (rem-m))//2)
    g += max(min(rem//k,n//k-g),1);
print(ans)
