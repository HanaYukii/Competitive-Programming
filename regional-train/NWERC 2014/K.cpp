#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 10000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
multiset<ll>pos;
ll ans[maxn];
ll n, m, t;
void solve(ll x){
    ll sum = 0;
    multiset<ll>st;
    st = pos;
    ll cur = x;
    while(st.size()){
        ll nxt;
        if(st.lower_bound(cur)==st.end()){
            nxt = *st.begin();
            sum += nxt - cur + m;
        }
        else{
            nxt = *st.lower_bound(cur);
            sum += nxt - cur;
        }
        st.erase(st.lower_bound(nxt));
        sum += t;
        cur = (nxt + t) % m;
    }
    ans[x] = sum;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    f(n){
        ll add;
        cin >> add;
        pos.insert(add);
    }
    f(n){
        if(pos.count(i)){
            solve(i);
        }
    }
    int left = m;
    int last = *pos.begin();
    int cur = last;
    int plus = 0;
    while(left--){
        cur--;
        if(cur < 0){
            cur += m;
        }
        if(!ans[cur]){
            plus++;
            ans[cur] = ans[last] + plus;
        }
        else{
            plus = 0;
            last = cur;
        }
    }
    ll sum = 0;
    ll mx = 0,mi = 9e18;
    ll bt = m;
    f(m){
        sum += ans[i];
        mi = min(mi,ans[i]);
        mx = max(mx,ans[i]);
    }
    ll g = __gcd(sum,bt);
    sum /= g;
    bt /= g;
    cout << mi << endl;
    cout << mx << endl;
    cout << sum <<'/'<<bt<<endl;
}
