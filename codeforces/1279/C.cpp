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
int b[maxn];
int pos[maxn];
int n, m;
void update(int x,int d){
    while(x <= n){
        b[x] += d;
        x += x & (-x);
    }
}
int sum(int x){
    int ret = 0;
    while(x){
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
void init(){
    for(int i = 0 ; i <= n ; i++){
        b[i] = 0;
    }
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        update(i,1);
        int add;
        cin >> add;
        pos[add] = i;
    }
}
void solve(){
    ll ans = 0;
    int mx = 0;
    for(int i = 0 ; i < m ; i++){
        int add;
        cin >> add;
        if(mx >= pos[add]){
            ans++;
        }
        else{
            mx = pos[add];
            int k = sum(pos[add]);
            ans += k * 2 - 1;
        }
        update(1,-1);
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        solve();
    }
}
