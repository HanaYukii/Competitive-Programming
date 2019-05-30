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
#define bg begin()
#define ed end()
#define pii pair<int,int>

int main(){
	ll n,m;
	while(cin >> n >> m){
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
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		if(v1[n-1]>v2[0]){
			cout<<-1<<endl;
		}
		else{
			ll sum=0;
			f(n){
				sum += v1[i] * m;
			}
			f(m){
				sum += v2[i] - v1[n-1];
			}
			if(v1[n-1]<v2[0]){
				sum -= v2[0] - v1[n-1];
				sum += v2[0] - v1[n-2];
			}
			cout << sum << endl;
		}
	}
}