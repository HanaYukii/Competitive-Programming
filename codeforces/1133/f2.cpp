#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int maxn=200005;
vector<int>g[maxn];
struct e{
    int f,s;
}cont[maxn];
int deg[maxn];
int d[maxn];
int fi(int x){
    return d[x]==x?x:d[x]=fi(d[x]);
}
int main(){
    int n,m,k;
    while(cin>>n>>m>>k){
        set<int>can;
        f(m){
            int add1,add2;
            cin>>add1>>add2;
            if(add2==1){
                swap(add1,add2);
            }
            cont[i].f=add1;
            cont[i].s=add2;
            g[add1].pb(add2);
            g[add2].pb(add1);
        }
        int u[n+5]={};
        for(auto i:g[1]){
            if(u[i]){
                continue;
            }
            else{
                queue<int>q;
                set<int>use;
                use.insert(1);
                use.insert(i);
                q.push(i);
                while(!q.empty()){
                    int now=q.front();
                    q.pop();
                    for(auto j:g[now]){
                        if(use.find(j)==use.end()){
                            use.insert(j);
                            q.push(j);
                        }
                        else if(j==1&&now!=i){
                            can.insert(now);
                            u[now]=1;
                        }
                    }
                }
            }
        }
        if(can.size()<g[1].size()-k){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            set<int>uc;
            for(auto i:can){
                if(uc.size()<g[1].size()-k){
                    uc.insert(i);
                }
                else{
                    break;
                }
            }
            f1(n)d[i]=i;
            f(m){
                if(cont[i].f==1&&uc.find(cont[i].s)==uc.end()){
                    cout<<cont[i].f<<' '<<cont[i].s<<'\n';
                    d[fi(cont[i].f)]=fi(cont[i].s);
                }
            }
            f(m){
                if(cont[i].f==1)continue;
                int x=fi(cont[i].f),y=fi(cont[i].s);
                if(x!=y){
                    cout<<cont[i].f<<' '<<cont[i].s<<'\n';
                    d[x]=y;
                }
            }
        }
    }
}