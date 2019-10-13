#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
//#define maxn 100005
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
	cin >> n;
	ll cont[n+5] = {};
	ll a[n+5] = {};
	int cnt[70] = {};
	int mx=0,idx=0;
	f(n){
		cin >> cont[i];
		ll tmp = cont[i];
		int cc = 0;
		while(tmp%2==0){
			tmp /= 2;
			cc++;
		}
		cnt[cc]++;
		if(mx<cnt[cc]){
			mx = cnt[cc];
			idx = cc;
		}
		a[i] = cc;
	}
	vector<ll>e;
	f(n){
		if(a[i]!=idx){
			e.pb(cont[i]);
		}
	}
	cout << e.size() << endl;
	for(auto i:e){
		cout<<i<<' ';
	}
	cout << endl;
}