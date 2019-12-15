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
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll ans = min({b,c,d})*f;
    for(int i = 1 ; i <= min(a,d) ; i++){
        ll cur = i * e;
        cur += min({b,c,d-i})*f;
        ans = max(ans,cur);
    }
    cout << ans << endl;
    
}
