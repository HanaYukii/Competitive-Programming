#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
vector<int>g[maxn];
ll num[maxn];
ll a[maxn];
int f;
void dfs(int now,int pre){
    if(num[now]==-1){
        ll Min=1e18;
        if(g[now].size()==0){
            Min=num[pre];
        }
        for(auto i:g[now]){
            Min=min(Min,num[i]);
            if(num[i]<num[pre]){
                f=1;
            }
        }
        num[now]=Min;
    }
    a[now]=num[now]-num[pre];
    for(auto i:g[now]){
        dfs(i,now);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    string s;
    int n;
    while(cin>>n){
        f=0;
        f1(n){
            g[i].clear();
        }
        ms(num);
        f(n-1){
            int add;
            cin>>add;
            g[add].pb(i+2);
        }
        f1(n){
            cin>>num[i];
        }
        a[1]=num[1];
        dfs(1,0);
        if(f){
            cout<<-1<<endl;
        }
        else{
            ll s=0;
            f1(n){
                s+=a[i];
            }
            cout<<s<<endl;
        }
    }
    
}