#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int nr[300005],nb[300005];
int c[300005],b,r;
int ans;
vector<int>g[300005];
void dfs(int now,int pre){
    if(c[now]==1)nb[now]++;
    else if(c[now])nr[now]++;
    for(auto i:g[now]){
        if(i!=pre){
            dfs(i,now);
            nb[now]+=nb[i];
            nr[now]+=nr[i];
        }
    }
    if((nr[now]==r&&nb[now]==0)||(nb[now]==b&&nr[now]==0)){
        ans++;
    }
}
int main(){
    int n;
    while(cin>>n){
        b=0,r=0;
        f1(n){
            cin>>c[i];
            if(c[i]==2)r++;
            else if(c[i])b++;
        }
        f1(n-1){
            int add1,add2;
            cin>>add1>>add2;
            g[add1].pb(add2);
            g[add2].pb(add1);
        }
        ans=0;
        dfs(1,0);
        cout<<ans<<endl;
    }
}