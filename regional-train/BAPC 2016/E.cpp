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
vector<pair<ll,ll> >g[maxn];
int n;
ll sp(ll x){
    ll dis[n+5] = {};
    f1(n){
        dis[i] = 1e18;
    }
    dis[1] = 0;
    set<pair<ll,int> >st;
    st.insert({0,1});
    while(st.size()){
        pair<ll,int>now = *st.begin();
        st.erase(now);
        for(auto i:g[now.S]){
            if(i.S > x)continue;
            if(now.F + i.S >= dis[i.F])continue;
            st.erase({dis[i.F],i.F});
            dis[i.F] = now.F + i.S;
            st.insert({dis[i.F],i.F});
        }
    }
    return dis[n];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, p;
    cin >> n >> m >> p;
    f(m){
        int add1, add2, d;
        cin >> add1 >> add2 >> d;
        g[add1].pb({add2,d});
        g[add2].pb({add1,d});
    }
    ll tar = sp(1e9);
    tar = tar * (100 + p) / 100;
    int l = 0, r = 1e9;
    while(r - l > 1){
        int m = (l + r) >> 1;
        ll d = sp(m);
        if(d > tar){
            l = m;
        }
        else{
            r = m;
        }
    }
    cout << l + 1 <<endl;
}
