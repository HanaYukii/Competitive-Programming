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
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0;
        vector<int>v;
        f(n){
            int add;
            cin >> add;
            v.pb(add);
        }
        sort(v.begin(),v.end());
        int dp[n+5] = {};
        dp[0] = 0;
        int mx = 0;
        for(int i = 1 ; i <= n ; i++){
            if(i<k){
                dp[i] = dp[i-1] + v[i-1];
            }
            else{
                dp[i] = dp[i-k] + v[i-1];
            }
            if(dp[i] <= m){
                mx = i;
            }
        }
        cout << mx << '\n';
    }
}
