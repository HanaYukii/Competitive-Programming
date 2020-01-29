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
set<int>st[maxn];
vector<pair<int,int> >ans;
void dfs(int now){
    while(st[now].size()){
        int nxt = *st[now].begin();
        st[nxt].erase(now);
        st[now].erase(nxt);
        ans.pb({now,nxt});
        dfs(nxt);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        ans.clear();
        cin >> n >> m;
        for(int i = 0 ; i < m ; i++){
            int x, y;
            cin >> x >> y;
            st[x].insert(y);
            st[y].insert(x);
        }
        for(int i = 1 ; i <= n ; i++){
            if(st[i].size() & 1){
                st[n+1].insert(i);
                st[i].insert(n+1);
            }
        }
        cout << n - st[n+1].size() << '\n';
        for(int i = 1 ; i <= n ; i++){
            dfs(i);
        }
        for(auto i:ans){
            if(i.F == n + 1 || i.S == n + 1){
                continue;
            }
            cout << i.F <<' '<<i.S << '\n';
        }
    }
}
