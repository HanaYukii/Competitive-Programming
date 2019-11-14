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
bool cmp(pair<ll,ll> x,pair<ll,ll>y){
    if(x.F != y.F){
        return x.F > y.F;
    }
    else{
        return x.S > y.S;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,ll> >v;
        vector<ll>mon;
        f1(n){
            ll add;
            cin >> add;
            mon.pb(add);
        }
        int m;
        cin >> m;
        f(m){
            ll add1, add2;
            cin >> add1 >> add2;
            v.pb({add2,add1});
        }
        sort(v.begin(),v.end(),cmp);
        vector<ll>real;
        map<ll,int>mp;
        ll last = 0;
        for(auto i:v){
           // cout << i.F <<' '<<i.S << endl;
            if(i.S > last){
                last = i.S;
                real.pb(i.S);
                mp[i.S] = i.F;
            }
        }
        int ptr = 0;
        int f = 0;
        int ans = 0;
        while(ptr < n){
            int cnt = 0;
            if(lower_bound(real.begin(),real.end(),mon[ptr])==real.end()){
                f = 1;
                break;
            }
            ans++;
            int u = *lower_bound(real.begin(),real.end(),mon[ptr]);
            int left = mp[u];
            //cout << u << endl;
           // cout << ptr << ' ' << left << endl;

            while(left--){
                if(ptr == n)break;
                if(mon[ptr]<=u){
                    ptr++;
                }
                else{
                    if(lower_bound(real.begin(),real.end(),mon[ptr])==real.end()){
                        f = 1;
                        break;
                    }
                    else{
                        int nxt = *lower_bound(real.begin(),real.end(),mon[ptr]);
                        int sw = mp[u] - mp[nxt];
                        //cout << left <<' '<<sw << endl;
                        if(left >= sw){
                            left -= sw;
                            ptr++;
                            u = nxt;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        if(f){
             cout << -1 << '\n';
        }
        else{
            cout << ans << '\n';
        }

    }
}
