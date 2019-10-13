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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,p,d,w;
    while(cin >> n >> p >> d >> w){
        ll num = p / d;
        int f = 0;
        for(ll i=num;i>=max(num-w,0LL);i--){
            ll left = p - d * i;
            if(left % w)continue;
            ll bc = left / w;
            if(bc+i<=n){
                cout<<i<<' '<<bc<<' '<<n-i-bc<<endl;
                f=1;
                break;
            }
        }
        if(!f){
            cout<<-1<<endl;
        }
    }
}