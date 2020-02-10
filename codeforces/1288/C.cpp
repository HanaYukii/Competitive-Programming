nclude<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll dp[1005][10] = {};
    ll dp2[1005][10] = {};
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = 1;
        dp2[i][0] = 1;
    }
    for(int i = 1 ; i < m ; i++){
        ll sum = 0;
        for(int j = 0 ; j < n ; j++){
            sum += dp[j][i-1];
            sum %= mod;
            dp[j][i] = sum;
            dp2[n-1-j][i] = sum;
        }
    }
    ll ans = 0;
    m--;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            ans += dp[i][m] * dp2[j][m];
            ans %= mod;
        }
    }
    cout << ans << '\n';
}
