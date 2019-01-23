#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
int main(void){
	ios_base::sync_with_stdio(false);
	ll n,l,r;
	while(cin>>n>>l>>r){
		l--;
		ll pre[3]={},now[3]={};
		ll num[3]={};
		num[0]=r/3-l/3;
		num[1]=(r/3+((r%3)>=1))-(l/3+((l%3)>=1));
		num[2]=(r/3+((r%3)>=2))-(l/3+((l%3)>=2));
		pre[0]=num[0],pre[1]=num[1],pre[2]=num[2];
		now[0]=pre[0];now[1]=pre[1];now[2]=pre[2];
		for(int i=1;i<n;i++){
			now[0]=((((pre[0]*num[0]%mod)+(pre[1]*num[2]%mod)%mod)+(pre[2]*num[1])%mod))%mod;
			now[1]=((((pre[0]*num[1]%mod)+(pre[1]*num[0]%mod)%mod)+(pre[2]*num[2])%mod))%mod;
			now[2]=((((pre[0]*num[2]%mod)+(pre[1]*num[1]%mod)%mod)+(pre[2]*num[0])%mod))%mod;
			pre[0]=now[0];pre[1]=now[1];pre[2]=now[2];
			//cout<<now[0]<<' '<<now[1]<<' '<<now[2]<<endl;
		}
		cout<<now[0]<<endl;
	}
}