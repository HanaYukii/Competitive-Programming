#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;

int main(){
	long long n,k;
	while(cin>>n>>k){
		ll r=0;
		ll add;
		ll ans=0;
		f(n){
			cin>>add;
			r+=add;
			if(r<=k&&i){
				r=0;
				ans++;
			}
			
			ans+=r/k;
			r%=k;
		}
		if(r){
			ans++;
		}
		cout<<ans<<endl;
	}	
}