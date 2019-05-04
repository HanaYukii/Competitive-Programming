#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n ,m;
		cin >> n >> m;
		ll cont[n+5] = {};
		ll mx=0;
		f(n){
			cin >> cont[i];
			mx=max(mx,cont[i]);
		}
		//cout<<mx<<endl;
		ll ans=0;
		for(ll i=1LL<<50;i;i>>=1){
			ll now=(1LL<<51)-i-ans;

			if(mx>now)continue;
			//cout<<now<<endl;
			int num=1;
			ll sum=cont[0];
			for(int j=1;j<n;j++){
				if(sum+cont[j]>now){
					num++;
					sum=cont[j];
				}
				else{
					sum+=cont[j];
				}
			}
			if(num<=m){
				ans += i;
			}
		}
		cout<<((1LL<<51)-ans)<<endl;
	}
	
}