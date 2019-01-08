#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	int pre[maxn]={};
	while(cin>>n>>k){
		int Min=200000;
		ms(pre);
		f(n){
			int add;
			cin>>add;
			pre[add]++;
			Min=min(Min,add);
		}
		for(int i=199999;i>Min;i--){
			pre[i]+=pre[i+1];
		}
		int now=0;
		int ans=0;
		for(int i=200000;i>Min;i--){
			if(now+pre[i]>k){
				ans++;
				now=pre[i];
			}
			else{
				now+=pre[i];
			}
		}
		if(now){
			ans++;
		}
		cout<<ans<<endl;
	}
}