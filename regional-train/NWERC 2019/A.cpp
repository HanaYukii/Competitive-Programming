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
int b[1000005];
void update(int x,int d){
    while(x<=1000000){
        b[x] += d;
        x += (x) & (-x);
    }
}
int sum(int x){
    int ret = 0;
    while(x){
        ret += b[x];
        x -= (x) & (-x);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int> >ans[n+5];
    unordered_map<int,unordered_set<int> >mp;
    int val[n+5] = {};
    f1(n)val[i] = 1;
    update(1,n);
    f1(n){
        mp[1].insert(i);
    }
    for(int j = 0 ; j < m ; j++){
        vector<int>st;
        int k;
        cin >> k;
        if(!k){
            if(j==0){
                f1(n){
                    ans[i].push_back({j,1});
                }
            }
            continue;
        }
        while(k--){
            int add;
            cin >> add;
            st.push_back(add);
        }
        unordered_set<int>mod;
        for(auto i:st){
            mod.insert(val[i]);
            mp[val[i]].erase(i);
            update(val[i],-1);
            val[i]++;
            update(val[i],1);
        }
        for(auto i:mod){
            int rk = n - sum(i) + 1;
            for(auto k:mp[i]){
                ans[k].push_back({j,rk});
            }
        }
        for(auto i:st){
            int rk = n - sum(val[i]) + 1;
            ans[i].push_back({j,rk});
            mp[val[i]].insert(i);
            if(!mp[val[i]-1].size()){
                mp.erase(val[i]-1);
            }
        }
    }
    if(!ans[1].size()){
        f1(n){
            cout<<"1.00000000"<<'\n';
        }
        exit(0);
    }
    f1(n){
        ans[i].pb({m,ans[i].back().S});
    }
    f1(n){
        double sum = 0;
        for(int j = 1 ; j < ans[i].size() ; j++){
            sum += (double)ans[i][j-1].S * (double)(ans[i][j].F - ans[i][j-1].F) ;
        }
        sum /= m;
        cout << fixed << setprecision(10) << sum << '\n';
    }

}
