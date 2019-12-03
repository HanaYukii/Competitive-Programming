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
int n;
ll dij(int s,int t){
    ll dis[n+5] = {};
    f(n){
        dis[i] = 1e18;
    }
    dis[s] = 0;
    set<pair<ll,int> >st;
    st.insert({0,s});
    while(st.size()){
        pair<ll,int>now = *st.begin();
        st.erase(now);
        for(auto i:g[now.S]){
            ll nxt = now.F + i.S;
            if(dis[i.F] > nxt){
                st.erase({dis[i.F],i.F});
                dis[i.F] = nxt;
                st.insert({dis[i.F],i.F});
            }
        }
    }
    //cout << dis[t] << endl;
    return dis[t];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    f(m){
        int add1, add2, add3;
        cin >> add1 >> add2 >> add3;
        g[add1].pb({add2,add3});
        g[add2].pb({add1,add3});
    }
    ll ans = dij(s,t);
    f(f){
        int add1, add2;
        cin >> add1 >> add2;
        g[add1].pb({add2,0});
        ans = min(ans,dij(s,t));
        g[add1].pop_back();
    }
    cout << ans << endl;
}
