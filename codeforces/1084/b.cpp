#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll cont[1005];
int main(){
    ios::sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    ll Min=1e18;
    for(int i=0;i<n;i++){
        cin>>cont[i];
        sum+=cont[i];
        Min=min(Min,cont[i]);
    }
    if(sum<m){
        cout<<-1<<endl;
        exit(0);
    }
    int ans=0;
    for(int i=1<<30;i;i>>=1){
        int test=ans+i;
        ll s=0;
        for(int j=0;j<n;j++){
            s+=cont[j]-test;
        }
        if(s>=m&&test<=Min){
            ans=test;
        }
    }
    cout<<ans<<endl;
    
}