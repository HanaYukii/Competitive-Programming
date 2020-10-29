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
const p1 = 114115;
vector<int>g[maxn][2];
set<int>st;
ll dfs(int now,int pre,int tp){
    ll ret = 1;
    vector<ll>v;
    for(auto i:g[now][tp]){
        if( i == pre)continue;
        v.pb(dfs(i,now,tp));
    }
    sort(v.rbegin(),v.rend());
    for(auto i:v){
        ret *= p1;
        ret += i;
        ret %= mod;
    }
    return ret;
}
int main(){
    // O(n^2) non rooted isomer
	int n, m;
    cin >> n;
    st.clear();
    // input tree1
    for (int i = 0 ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;
        g[x][0].pb(y);
        g[y][0].pb(x);
    }
    // input tree2
    for (int i = 0 ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;
        g[x][1].pb(y);
        g[y][1].pb(x);
    }
    for (int i = 1 ; i <= n ; i++){
        st.insert(dfs(i,i,0));
        // rooted at i;
    }
    if(st.count(dfs(1,1,1))){
        cout << "Same" << '\n';
    }
    else{
        cout << "Different" << '\n';
    }
}
