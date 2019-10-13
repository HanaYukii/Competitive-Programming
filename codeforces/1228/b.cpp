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
const ll mod =1e9+7;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int>v1,v2;
	v1.pb(0);
	v2.pb(0);
	f(n){
		int add;
		cin >> add;
		v1.pb(add);
	}
	f(m){
		int add;
		cin >> add;
		v2.pb(add);
	}
	ll ans = 1;
	f1(n){
		fr(j,1,m+1){
			if((v1[i]==j-1&&v2[j]>=i)||(v1[i]>=j&&v2[j]==i-1)){
				cout<<0<<endl;
				exit(0);
			}
			else{
				if(i>v2[j]+1&&j>v1[i]+1){
					ans*=2;
					ans %= mod;
				}
			}
		}
	}
	cout << ans << endl;
}
