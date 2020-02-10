#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll>v(n);
    for(auto &i:v){
        cin >> i;
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    f(n - k){   
        ans += v[i];
    }
    cout << ans << '\n';
}
