// Bipartite Matching
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
vector<int>g[MAXN];
int c[MAXN];
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
        for (int i = 1; i <= n; i++){
            g[i].clear();
        }
        for (int i = 0; i < m; i++){
            int add1, add2;
            cin >> add1 >> add2;
            g[add1].push_back(add2);
            g[add2].push_back(add1);
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
