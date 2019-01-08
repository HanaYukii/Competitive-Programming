#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main()
{

    int n;  
    while(cin>>n){
        vector<ll>x,y;
        for(int i=0;i<n;i++){
            ll add1,add2;
            cin>>add1>>add2;
            x.pb(add1);
            y.pb(add2);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        ll ans=n;
        for(int i=0;i<n;i++){
            ans+=max(x[i],y[i]);
        }
        cout<<ans<<endl;
    }
}