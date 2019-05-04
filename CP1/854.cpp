#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll mod=1e9+7;
ll inv(ll x,ll p){
    ll ret=1;
    while(p){
        if(p&1){
            ret*=x;
            ret%=mod;
        }
        x=x*x%mod;
        p>>=1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll a,p;
        cin >> a >> p;
        mod = p;
        cout<<inv(a,p-2)<<endl;
    }
}