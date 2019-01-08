#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 10005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	ll n,m;
	while(cin>>n>>m){
		ll cont[n+5]={};
		for(int i=0;i<n;i++){
			cin>>cont[i];
		}
		ll ans=0;
		
		while(1){
			ll sum=0;
			ll tmpm=m;
			ll cnt=0;
			for(int i=0;i<n;i++){
				if(tmpm>=cont[i]){
					tmpm-=cont[i];
					cnt++;
					sum+=cont[i];
				}
			}
			if(cnt==0)
				break;
			ll k=m/sum;
			ans+=cnt*k;
			m%=sum;
		}
		cout<<ans<<endl;
	}	
}