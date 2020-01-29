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
vector<int>g[maxn];
int c[maxn];
int dfs(int now,int x){
    c[now] = x;
    int ret = 0;
    for(auto i:g[now]){
        if(c[now] == c[i]){
            return 1;
        }
        if(~c[i])continue;
        ret |= dfs(i,x^1);
    }
    return ret;
}
int main(){
	int n, m;
    while(cin >> n >> m && n){
        f1(n){
            g[i].clear();
        }
        f(m){
            int add1, add2;
            cin >> add1 >> add2;
            g[add1].pb(add2);
            g[add2].pb(add1);
        }
        for(int i = 1 ; i <= n ; i++){
            c[i] = -1;
        }
        int ret = 0;
        for(int i = 1 ; i <= n ; i++){
            if(~c[i])continue;
            ret |= dfs(i,0);
        }
        if(ret){
            cout << "No" << '\n';
        }
        else{
            cout << "Yes" << '\n';
        }
    }
}
