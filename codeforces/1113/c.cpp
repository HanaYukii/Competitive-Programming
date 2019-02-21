#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	int n;
	while(cin>>n){
		map<ll,int>mp1,mp2;
		mp1[0]=1;
		ll nxor=0;
		ll ans=0;
		f(n){
			ll add;
			cin>>add;
			nxor^=add;
			if(i&1){
				ans+=mp1[nxor];
				mp1[nxor]++;
			}
			else{
				ans+=mp2[nxor];
				mp2[nxor]++;
			}
		}
		cout<<ans<<endl;
	}
}