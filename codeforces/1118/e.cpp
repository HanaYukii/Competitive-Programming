#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const int mod=1e9+7;
int main(){
	ll n,m;
	while(cin>>m>>n){
		ll ans = n*(n-1);
		if(ans<m){
			cout<<"NO"<<endl;
			exit(0);
		}
		int aaa;
		cout<<"YES"<<endl;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<i<<' '<<j<<'\n';
				m--;
				if(!m)exit(0);
				cout<<j<<' '<<i<<'\n';
				m--;
				if(!m)exit(0);
			}
		}
	}
}