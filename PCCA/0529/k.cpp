#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
#define maxn 500

int main() {
	int n;
	while(cin >> n){
		vector<ll>v;
		ll sum = 0;
		f(n){
			ll add;
			cin >>add;
			sum += add;
			v.pb(add);
		}
		
		ll suma=0;
		multiset<ll>st;
		for(int i=1;i<n;i+=2){
			st.insert(v[i]);
			st.insert(v[i-1]);
			ll now=*st.begin();
			suma+=now;
			//sum += now;
			st.erase(st.lower_bound(now));
		}
		cout<<sum-suma<<' '<<suma<<endl;
	}
}