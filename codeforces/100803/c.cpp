#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    
    while(cin>>n>>m){
        int fa[1200]={};
        f1(n+1){
            fa[i]=i;
        }
        f(m){
            int add1,add2;
            cin>>add1>>add2;
            fa[add1]=max(fa[add1],add2);
        }
        ll ans=n+1;
        for(int i=1;i<=n;){
            int r=fa[i];
            int now=i;
            while(now<=r){
                r=max(r,fa[now]);
                now++;
            }
            ans+=2*(r-i);
            i=now;
        }
        cout<<ans<<endl;
    }
    
}