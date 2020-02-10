#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    int n, m;
    cin >> n >> m;
    int cont[n][m] = {};
    int tar[n][m] = {};
    int cur = 1;
    f(n){
        fr(j,0,m){
            cin >> cont[i][j];
            tar[i][j] = cur++;
        }
    }
    ll ans = 0;
    f(m){
        int cnt[n+5] = {};
        fr(j,0,n){
            if(cont[j][i] <= n * m &&(cont[j][i] - tar[j][i])% m == 0){
                int tt = (tar[j][i] - cont[j][i])/m;
                tt += n;
                tt %= n;
                cnt[tt]++;
            }
        }
        int mi = 1e9;
        fr(j,0,n){
            mi = min(mi,n-cnt[j]+j);
        }
        ans += mi ;
    }
    cout << ans << endl;
}
