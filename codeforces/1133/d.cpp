#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back

int main(void){
	ios_base::sync_with_stdio(false);
	int n;
	while(cin>>n){
		ll a[n+5]={};
		ll g[n+5]={};
		f(n)cin>>a[i];
		f(n)cin>>g[i];
		map<pair<ll,ll>,int >mp;
		int all=0;
		f(n){
			ll d=0-g[i];
			if(a[i]<0){
				a[i]=-a[i];
				d=-d;
			}
			if(a[i]==0&&d!=0){

			}
			else if(a[i]==0&&d==0){
				all++;
			}
			else{
				int gcd=abs(__gcd(a[i],d));
				a[i]/=gcd;
				d/=gcd;
				mp[{a[i],d}]++;
			}
		}
		int mx=all;
		for(auto i:mp){
			mx=max(mx,all+i.second);
		}
		cout<<mx<<endl;
	}
}