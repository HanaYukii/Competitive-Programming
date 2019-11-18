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
vector<pair<int,int> >g[maxn];
int a[maxn];
void dfs(int now,int pre,int x){
    a[now] = x;
    for(auto i:g[now]){
        if(i.F == pre)continue;
        dfs(i.F,now,x^i.S);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    f(n-1){
        int add1, add2, add3;
        cin >> add1 >> add2 >> add3;
        g[add1].pb({add2,add3});
        g[add2].pb({add1,add3});
    }
    dfs(1,0,0);
    ll ans = 0;
    for(int i = 30 ; i >= 0 ; i--){
        ll cnt = 0;
        fr(j, 1, n + 1){
            if(a[j] & (1<<i)){
                cnt++;
            }
        }
        ans += cnt * (n - cnt) * (1 << i);
    }
    cout << ans << endl;
}
