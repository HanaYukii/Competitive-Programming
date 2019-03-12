#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
const int mod=1e9+7;
int main(){
	ll x,y;
    int n;
    while(cin>>n){
        x=0,y=0;
        ll ans=1;
        ll mx=0;
        f(n){
            ll add1,add2;
            cin>>add1>>add2;
            ll bt=max(x,y);
            ll up=min(add1,add2);
            if(up<bt){
                x=add1,y=add2;
                continue;
            }
            if(mx==bt)
                ans+=max(0LL,up-bt);
            else{
                ans+=max(0LL,up-bt+1);
            }
            mx=up;
            x=add1,y=add2;
        }
        cout<<ans<<endl;
    }
}