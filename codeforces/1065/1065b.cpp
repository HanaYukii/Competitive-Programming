#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,m;
	while(cin>>n>>m){
		ll minn=max(0LL,n-(m<<1));
		ll ans=0;
		int f=0;
		for(int i=1<<17;i;i>>=1){
			if((ans+i)*(ans+i-1)/2<m){
				ans+=i;
			}
			else if((ans+i)*(ans+i-1)/2==m){
				ans+=i;
				f=1;
			}
		}
		ans+=!f;
		if(!m){
			ans=0;
		}
		cout<<minn<<' '<<n-ans<<endl;
	}
}