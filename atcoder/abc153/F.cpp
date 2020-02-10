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
const int mod = 1e9+7;
ll b[200005];
void update(int x,ll d){
    while(x <= 200000){
        b[x] += d;
        x += x & (-x);
    }
}
ll sum(int x){
    ll ret = 0;
    while(x){
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll,ll> >v;
    f(n){
        int x, y;
        cin >> x >> y;
        v.pb({x,y});
    }
    v.pb({-1e9,-1e9});
    sort(v.begin(),v.end());
    vector<ll>pos;
    for(auto i:v){
        pos.pb(i.F);
    }
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        ll left = v[i].S - sum(i);
        if(left <= 0){
            continue;
        }
        ll cnt = (left - 1) / k + 1;
        ans += cnt;
        ll last = upper_bound(pos.begin(),pos.end(),pos[i]+2*m)-pos.begin();
        update(i,cnt * k);
        update(last,-cnt * k);
    }
    cout << ans << '\n';
}
