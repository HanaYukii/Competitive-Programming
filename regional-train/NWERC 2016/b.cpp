#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define ms1(i) memset(i,-1,sizeof(i))
#define F first
#define S second
set<int>g[maxn];
vector<pair<int,int> >g2[maxn<<1];
stack<int>st;  
int n,m,scc,INDEX;  
int low[maxn],dfn[maxn],instack[maxn],fa[maxn];  
int gp[maxn][3];
vector<int>sg[maxn];
int dp[maxn<<1];
void init(){
    scc = INDEX = 0;
    while(!st.empty())st.pop();
    for(int i=0;i<maxn;i++)g[i].clear();
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(low,0,sizeof(low));
    memset(fa,0,sizeof(fa));
}
void tarjan(int now){
    dfn[now] = low[now] = ++INDEX;
    instack[now] = 1;
    st.push(now);
    for(auto i:g[now]){
        if(!dfn[i]){
            tarjan(i);
            low[now] = min(low[now],low[i]);
        }
        else if(instack[i]){
            low[now] = min(low[now],dfn[i]);
        }
    }
    if(dfn[now] == low[now]){
        scc++;
        while(1){
            int cur = st.top();
            st.pop();
            instack[cur] = 0;
            fa[cur] = scc;
            sg[scc].pb(cur);
            if(cur == now)break;
        }
    }
}
void check(){
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
}
void builds(int x){
    map<pair<int,int> , int>mp;
    sort(sg[x].begin(),sg[x].end());
    do{
        int cur = 1;
        int last = sg[x][0];
        mp[{sg[x][0],last}] = 1;
        while(g[last].count(sg[x][cur])){
            last = sg[x][cur];
            cur++;
            mp[{sg[x][0],last}] = max(mp[{sg[x][0],last}],cur);
        }
    }while(next_permutation(sg[x].begin(),sg[x].end()));
    for(auto i:mp){
        int num1 = i.F.F;
        int num2 = i.F.S;
        int dis = i.S;
        //cout<<num1<<' '<<num2<<' '<<dis<<endl;
        g2[num1].pb({num2+n,dis});
    }
}
int solve(int x){
    if(~dp[x])return dp[x];
    int mx = 0;
    for(auto i:g2[x]){
        mx = max(mx,solve(i.F)+i.S);
    }
    return dp[x] = mx;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    f(m){
        int add1,add2;
        cin >> add1 >> add2;
        g[add1].insert(add2);
    }
    check();
    f1(scc){
        builds(i);
    }
    f1(n){
        for(auto j:g[i]){
            if(fa[j]!=fa[i]){
                g2[i+n].pb({j,0});
            }
        }
    }
    ms1(dp);
    int ans = 0;
    f1(n*2){
        ans = max(ans,solve(i));
    }
    cout << ans << endl;
}
