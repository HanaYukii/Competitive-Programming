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
	int n,k;
	while(cin>>n){
		vector<int>cont;
		f(n){
			int add;
			cin>>add;
			cont.pb(add);
		}
		sort(cont.begin(),cont.end());
		int mx=0;
		for(int i=0;i<n;i++){
			mx=max(mx,upper_bound(cont.begin(),cont.end(),cont[i]+5)-lower_bound(cont.begin(),cont.end(),cont[i]));
		}
		cout<<mx<<endl;
	}
}