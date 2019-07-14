#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const ll inf=1e10;
int main()
{
    int n,k;
    cin >> n >> k;
   	ll cont[n+5] = {};
   	vector<ll>suf;
   	ll ans = 0;
   	f(n){
   		cin >> cont[i];
   		ans += cont[i];
   	}
    ll sum = 0;
    for(int i = n-1;i>0;i--){
    	sum += cont[i];
    	suf.pb(sum);
    }
    sort(suf.begin(),suf.end());
    for(int i=n-2;i>=n-k;i--){
    	ans += suf[i];
    }
    cout << ans << endl;
}