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
	while(cin>>n>>k){
		map<int,int>mp;
		f(n){
			int add;
			cin>>add;
			mp[add%k]++;
		}
		ll sum=0;
		for(auto i:mp){
			if(i.first==0||i.first*2==k){
				sum+=i.second/2*2;
			}
			else if(i.first<=k/2){
				sum+=min(i.second,mp[k-i.first])*2;
			}
			else{
				break;
			}
		}
		cout<<sum<<endl;
	}
}