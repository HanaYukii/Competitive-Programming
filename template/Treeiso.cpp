// Tree Isomorphism
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const int mod = 1e9 + 7;
const p1 = 114115;
vector<int>g[MAXN][2];
set<int>st;
long long dfs(int now,int pre,int tp){
    long long ret = 1;
    vector<long long>v;
    for(auto i:g[now][tp]){
        if( i == pre)continue;
        v.push_back(dfs(i,now,tp));
    }
    sort(v.rbegin(),v.rend());
    for(auto i:v){
        ret *= p1;
        ret += i;
        ret %= mod;
    }
    return ret;
}
int main(){
    // O(n^2) non rooted isomer
	int n, m;
    cin >> n;
    st.clear();
    // input tree1
    for (int i = 0 ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;
        g[x][0].push_back(y);
        g[y][0].push_back(x);
    }
    // input tree2
    for (int i = 0 ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;
        g[x][1].push_back(y);
        g[y][1].push_back(x);
    }
    for (int i = 1 ; i <= n ; i++){
        st.insert(dfs(i,i,0));
        // rooted at i;
    }
    if(st.count(dfs(1,1,1))){
        cout << "Same" << '\n';
    }
    else{
        cout << "Different" << '\n';
    }
}
