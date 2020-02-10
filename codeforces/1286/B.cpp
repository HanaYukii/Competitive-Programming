#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
int sz[2005];
int nd[2005];
vector<int>g[2005];
int ans[2005];
int dfs1(int now){
  sz[now] = 1;
  for(auto i:g[now]){
    sz[now] += dfs1(i);
  }
  return sz[now];
}
void dfs2(int now,vector<int>v){
  ans[now] = v[nd[now]];
  int ptr = 0;
  for(auto i:g[now]){
    vector<int>vv;
    while((int)vv.size()<sz[i]){
      if(ptr == nd[now]);
      else vv.pb(v[ptr]);
      ptr++;
    }
    dfs2(i,vv);
  }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        int rt;
        f1(n){
          int add;
          cin >> add;
          if(add==0)rt = i;
          g[add].pb(i);
          cin >> nd[i];
        }
        dfs1(rt);
        f1(n){
          if(nd[i] >= sz[i]){
            cout << "NO\n";
            exit(0);
          }
        }
        vector<int>v;
        f1(n){
          v.pb(i);
        }
        dfs2(rt,v);
        cout << "YES\n";
        f1(n){
          cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    
    
}
