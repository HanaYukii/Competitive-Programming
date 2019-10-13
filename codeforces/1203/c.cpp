#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
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
	int n;
	while(cin >> n){
		ll gcd = 0;
		f(n){
			ll add;
			cin >> add;
			gcd = __gcd(gcd,add);
		}
		int ans = 0;
		for(ll i=1;i<=sqrt(gcd);i++){
			if(gcd%i)continue;
			if(i*i==gcd)ans++;
			else ans+=2;
		}
		cout << ans << endl;
	}
}