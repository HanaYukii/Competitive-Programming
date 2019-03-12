#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int maxn=2005;
int d[maxn];
//int rel[maxn][maxn];
set<int>g[maxn];
vector<int>rev[maxn];
int fi(int x){
    return d[x]==x?x:d[x]=fi(d[x]);
}
int v[maxn];
int c[maxn],f;
int deg[maxn];
set<int>dsu;
/*void dfs(int now){
    if(!rev[now].size()){
        v[now]=1;
        return;
    }
    else{
        int mx=0;
        for(auto i:rev[now]){
            if(!v[i])
                dfs(i);
            mx=max(mx,v[i]);
        }
        v[now]=mx+1;
    }
}*/
int topo(int x){
    int u[x+5]={};
    while(1){
        int f=0;
        f1(x){
            if(!u[i]&&!deg[i]){
                if(!v[i])v[i]=1;
                u[i]=1;
                for(auto j:g[i]){
                    deg[j]--;
                    v[j]=max(v[j],v[i]+1);
                }
                f=1;
            }
        }
        if(!f)break;
    }
    int ret=1;
    f1(x)ret&=u[i];
    return ret;
}
int main(){
    int n,m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m){
        string s[n+5];
        f(n){
            cin>>s[i];
        }
        f1(n+m){
            d[i]=i;
        }
        f(n){
            fr(j,0,m){
                if(s[i][j]=='='){
                    int x=fi(i+1);
                    int y=fi(n+1+j);
                    d[x]=y;
                }
            }
        }
        f1(n+m){
            d[i]=fi(i);
            dsu.insert(d[i]);
        }
        f(n){
            fr(j,0,m){
                if(s[i][j]=='<'){
                    int x=fi(i+1);
                    int y=fi(n+1+j);
                    g[x].insert(y);
                }
                else if(s[i][j]=='>'){
                    int x=fi(i+1);
                    int y=fi(n+1+j);
                    g[y].insert(x);
                }
            }
        }
        f=0;
        f1(n+m){
            for(auto j:g[i]){
                deg[j]++;
            }
        }
        f=topo(n+m);
        if(!f){
            cout<<"No"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            f1(n){
                cout<<v[d[i]]<<' ';
            }
            cout<<endl;
            f1(m){
                cout<<v[d[n+i]]<<' ';
            }
            cout<<endl;
        }
    }
}