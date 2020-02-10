#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
ll phi(ll x){
    ll ret = x;
    ll tmp = x;
    for(int i = 2 ; i <= sqrt(tmp) ; i++){
        if(tmp % i)continue;
        ret /= i;
        ret *= i - 1;
        while(tmp % i == 0){
            tmp /= i;
        }
    }
    if(tmp > 1){
        ret /= tmp;
        ret *= tmp - 1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll a, m;
        cin >> a >> m;
        cout << phi(m/__gcd(a,m)) << '\n';
    }
}
