#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    int n,m,k;
    while(cin>>n>>m>>k){
        int cont[n+5]={};
        f(n)cin>>cont[i];
        vector<int>v;
        f1(n-1)v.pb(cont[i]-cont[i-1]-1);
        sort(v.begin(),v.end());
        ll ans=n;
        f(n-k)ans+=v[i];
        cout<<ans<<endl;
    }
}