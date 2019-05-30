#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=998244353;

int main(){
	ll n;
	cin >> n;
	vector<ll>v1,v2;
	f(n){
		ll add;
		cin>>add;
		add *= (i+1);
		add *= (n-i);
		v1.pb(add);
	}
	f(n){
		int add;
		cin >> add;
		v2.pb(add);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	ll sum = 0;
	f(n){
		sum += (v1[i]%mod)*(v2[n-1-i])%mod;
		sum %= mod;
	}
	cout << sum << endl;
}