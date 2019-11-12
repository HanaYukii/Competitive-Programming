#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 123456789;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll pre[n+5] = {};
    ll num[n+5] = {};
    pre[0] = 1;
    num[0] = 1;
    ll sum = 1;
    for(int i = 1 ; i <= m ; i++){
        num[i] = sum;
        pre[i] = pre[i-1] + sum;
        pre[i] %= mod;
        sum += num[i];
        sum %= mod;
    }
    for(int i = m + 1 ; i <= n+1 ; i++){
        ll cnt = pre[i-1] - pre[i-m-1];
        cnt += mod;
        cnt %= mod;
        num[i] = cnt;
        pre[i] = (pre[i-1] + cnt) % mod;
    }
    ll ans = 0;
    for(int i = 1 ; i <= m ;i++){
        ans += num[n-i] * i;
        ans %= mod;
    }
    cout << ans << endl;
}
