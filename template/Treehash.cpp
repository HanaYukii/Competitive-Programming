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
vector<int>g[maxn][2];
set<int>st;
ll dfs(int now,int pre,int tp){
    ll ret = 73;
    vector<ll>v;
    for(auto i:g[now][tp]){
        if( i == pre)continue;
        v.pb(dfs(i,now,tp));
    }
    sort(v.rbegin(),v.rend());
    for(auto i:v){
        ret *= 6171;
        ret += i;
        ret %= mod;
    }
    return ret;
}
int main(){
	int n, m;
    while(cin >> n && n){
        f1(n){
            g[i][0].clear();
            g[i][1].clear();
        }
        st.clear();
        f(n-1){
            int add1, add2;
            cin >> add1 >> add2;
            g[add1][0].pb(add2);
            g[add2][0].pb(add1);
        }
        f(n-1){
            int add1, add2;
            cin >> add1 >> add2;
            g[add1][1].pb(add2);
            g[add2][1].pb(add1);
        }
        f1(n){
            //cout << dfs(i,i,0) <<' '<<dfs(i,i,1) << endl;;
            st.insert(dfs(i,i,0));
        }
        if(st.count(dfs(1,1,1))){
            cout << "Same" << '\n';
        }
        else{
            cout << "Different" << '\n';
        }
                
    }
}
