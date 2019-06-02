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
	ll n,k;
	while(cin >> n >> k){
		ll c[n+5]={};
		ll now = 1;
		for(int i=0;i<n;i++){
			c[i]=now;
			ll add;
			cin >> add;
			if(now<k){
				now *=add;
			}
		}
		c[n]=now;
		ll sum = 0;
		for(int i=n;i>=0;i--){
			if(c[i]==0)continue;
			sum += k/c[i];
			k %=c[i];
		}
		cout << sum << endl;
	}
}