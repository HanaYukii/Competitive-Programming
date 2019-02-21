#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
vector<ll>pos;
long long a,b,n,k;
long long solve(ll l,ll r){
    if(l==r){
        if(*lower_bound(pos.begin(),pos.end(),l)!=l)
            return a;
        else
            return b*(upper_bound(pos.begin(),pos.end(),r)-lower_bound(pos.begin(),pos.end(),l));
    }
    if(lower_bound(pos.begin(),pos.end(),l)==pos.end()||*lower_bound(pos.begin(),pos.end(),l)>r){
        return a;
    }
    ll mid=(l+r)/2;
    ll am=upper_bound(pos.begin(),pos.end(),r)-lower_bound(pos.begin(),pos.end(),l);
    ll Min=am*(r-l+1)*b;
    //cout<<Min<<endl;
    return min(Min,solve(l,mid)+solve(mid+1,r));
    
}
int main(){
    //int n,k,a,b;
    while(cin>>n>>k>>a>>b){
        f(k){
            ll add;
            cin>>add;
            pos.pb(add);
        }
        sort(pos.begin(),pos.end());
        cout<<solve(1,1<<n)<<endl;
    }
}