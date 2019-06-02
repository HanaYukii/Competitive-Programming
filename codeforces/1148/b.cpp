#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,k,ta,tb;
	while(cin >> n >> m >> ta >> tb >> k ){
		vector<ll>v1,v2;
		f(n){
			ll add;
			cin >> add;
			v1.pb(add);
		}
		f(m){
			ll add;
			cin >> add;
			v2.pb(add);
		}
		ll mx = 0;
		if(k>=n||k>=m){
			cout << -1 <<endl;
			exit(0);
		}
		for(int i=k;i>=0;i--){
			int left = k-i;
			int fok=lower_bound(v2.begin(),v2.end(),v1[i]+ta)-v2.begin();
			//cout <<fok <<' '<<left <<endl;
			if(fok+left>=m){
				cout<<-1<<endl;
				exit(0);
			}
			mx = max(mx,v2[fok+left]+tb);
		}
		cout << mx << endl;
	}
	
}