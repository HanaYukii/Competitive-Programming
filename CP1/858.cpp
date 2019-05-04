#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int n,m,q;
    while(cin >> n >> q){
        ll cont[n+5] = {};
        ll ans=0;
        f(n){
            cin>>cont[i];
        }
        for(ll i=1LL<<60;i;i>>=1){
            ll now = (1LL<<60)-i-ans;
            ll mx=0;
            ll cnt=1;
            ll f=0;
            ll len=0;
            for(int j=0;j<n;j++){
                if(cont[j]>now){
                    f=1;break;
                }
                len++;
                mx=max(mx,cont[j]);
                if(len*mx>now){
                    len=1;
                    mx=cont[j];
                    cnt++;
                }
            }
            if(!f&&cnt<=q){
                ans += i;
            }
        }
        cout<<(1LL<<60)-ans<<endl;
    }
        
}