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
bool cmp(pair<int,int>x,pair<int,int>y){
    return x.S<y.S;
}

vector<pair<int,int> >v;
ll tot,n;
bool check(ll tar){
    int cnt1 = 0;
    int ex = -1;
    int g[n+5]={};
    int cur = 0;
    int mx = 0;
    for(auto i:v){
        if(i.S>=tar && i.F>mx){
            ex = cur;
            mx = i.F;
        }
        if(i.S<tar){
            g[cur]=1;
            cnt1++;
            if(cnt1>n/2){
                return 0;
            }
        }
        cur++;
    }
    if(ex==-1){
        return 0;
    }
    g[ex]=3;
    int need = n/2-cnt1;
    set<pair<int,int> >st;
    if(need){
        for(int i=0;i<v.size();i++){
            if(g[i])continue;
            if(st.size()<need){
                st.insert({v[i].F,i});
            }
            else{
                if(v[i].F<(*(--st.end())).F){
                    st.erase(--st.end());
                    st.insert({v[i].F,i});
                }
            }
        }
        for(auto i:st){
            g[i.S]=1;
        }
    }
    f(n){
        if(g[i]==0){
            g[i]=2;
        }
    }
    //cout<<tar<<endl;
    //f(n){
      //  cout<<g[i]<<' ';
   // }
    //cout << endl;
    ll sum = 0;
    f(n){
        if(g[i]==1){
            sum += v[i].F;
        }
        else if(g[i]==2){
            sum += min((ll)v[i].F,tar);
        }
        else{
            sum += tar;
        }
    }
    if(sum <= tot){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        v.clear();
        cin >> n >> tot;
        f(n){
            ll add1,add2;
            cin >> add1 >> add2;
            v.pb({add1,add2});
        }
        sort(v.begin(),v.end(),cmp);
        ll ans = 0;
        for(ll i=1LL<<31;i;i>>=1){
            ll now = ans + i;
            if(check(now)){
                ans += i;
            }
        }
        cout << ans << endl;
    }
}
