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
ll cal1(ll x){
	ll ub = 10;
	ll lb = 1;
	ll low = 0;
	ll del = 1;
	ll ret = 0;
	while(ub-1<=x){
		ret += (ub - lb) * (low*2 + del * (ub - lb + 1)) / 2;
		low += (ub - lb) * del;
		del++;
		ub *= 10;
		lb *= 10;
	}
	ret += (x - lb + 1) * (low*2 + del * (x - lb + 2)) / 2;
	return ret;
}
int cal2(ll x){
	ll low = 1;
	ll num = 9;
	ll sig = 1;
	while(x>sig * num){
		x -= sig * num;
		num *= 10;
		sig++;
		low *= 10;
	}
	low += (x-1) / sig;
	x = (x-1) % sig + 1;
	vector<int>v;
	while(low){
		v.pb(low%10);
		low /= 10;
	}
	reverse(v.begin(),v.end());
	return v[x-1];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//ll x;
	//ll last = 0;
	int t;
	//cout<<cal1(0)<<endl;
	cin >> t;
	while(t--){
		ll x;
		cin >> x;
		int now = 0;
		for(int i=1<<29;i;i>>=1){
			int cur = now + i;
			if(cal1(cur)<x){
				now = cur;
			}
		}
		x -= cal1(now);
		now++;
		cout<<cal2(x)<<'\n';
	}
}