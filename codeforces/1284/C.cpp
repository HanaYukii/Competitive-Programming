#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
ll p[maxn];
ll sq[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    p[1] = 1;
    p[0] = 1;
    for(int i = 2 ; i <= n ; i++){
        p[i] = (p[i-1] * i) % m;
    }
    for(ll i = 1 ; i <= n ; i++){
        sq[i] = (i * i) % m;
    }
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        ans += sq[n+1-i] * p[i] % m * p[n-i] % m;
        ans %= m;
    }
    cout << ans << '\n';
}
