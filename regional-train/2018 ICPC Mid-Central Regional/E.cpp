#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second

int sign[10000005];
int gg[10000005];
int p[10000005];
int fac[10000005];
void build(){
    for(int i=2;i<=10000000;i++){
        //cout << i << endl;
        if(!p[i]){
            fac[i]=1;
            for(int j=i*2;j<=10000000;j+=i){
                p[j]=1;
                fac[j]++;
            }
            if((ll)i*i<=10000000)
            for(int j=i*i;j<=10000000;j+=i*i){
                gg[j]=1;
            }
        }
        if(gg[i])continue;
        if(fac[i]&1){
            sign[i]=-1;
        }
        else{
            sign[i]=1;
        }
    }
}
ll solve(ll x,ll y){
    ll ret = x*y;
    for(int i=2;i<=min(x,y);i++){
        if(!sign[i])continue;
        ret += sign[i] * (x/i) * (y/i);
    }
    return ret;
}
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    build();
    ll ans = 0;
    ans += solve(b,d);
    ans -= solve(a-1,d);
    ans -= solve(b,c-1);
    ans += solve(a-1,c-1);
    cout << ans << endl;
}
