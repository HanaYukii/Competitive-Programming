#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll>pf;
    if(n == 1){
        cout << 1 <<' '<<1<<endl;
        exit(0);
    }
    for(int i = 2 ; i <= sqrt(n);i++){
        if(n%i)continue;
        ll cur = 1;
        while(n % i == 0){
            cur *= i;
            n /= i;
        }
        pf.pb(cur);
    }
    if(n > 1){
        pf.pb(n);
    }
    ll ans1 = 1e18,ans2 = 1e18;
    ll mx = 1e18;
    for(int i = 0 ; i < (1<<pf.size()) ; i++){
        ll c1 = 1,c2 = 1;
        for(int j = 0 ; j < pf.size() ; j++){
            if((1<<j)&i){
                c1 *= pf[j];
            }
            else{
                c2 *= pf[j];
            }
        }
        if(max(c1,c2)<mx){
            mx = max(c1,c2);
            ans1 = c1;
            ans2 = c2;
        }
    }
    cout << ans1 <<' '<<ans2 << '\n';
}
