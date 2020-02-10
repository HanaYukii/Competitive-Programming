#include<bits/stdc++.h>
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
    int cont[n][m];
    int inv = (1<<m)-1;
    f(n){
        fr(j,0,m){
            cin >> cont[i][j];
        }
    }
    int ans1 = 1, ans2 = 1;
    int l = 0, r = 1e9+1;
    while(r - 1 > l){
        int mid = (l + r) >> 1;
        int dp[1<<m] = {};
        ms1(dp);
        int f = 0;
        for(int i = 0 ; i < n ; i++){
            int mask = 0;
            for(int j = 0 ; j < m ; j++){
                if(cont[i][j] >= mid){
                    mask |= (1<<j);
                }
            }
            if(~dp[mask^inv]){
                ans1 = i + 1;
                ans2 = dp[mask^inv] + 1;
                f = 1;
                break;
            }
            else{
                for (int s=mask; ; s=(s-1)&mask) {
                    dp[s] = i;
                    if (s==0)  break;
                }
            }
        }
        if(f){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << ans1 <<' '<<ans2 << '\n';
}
