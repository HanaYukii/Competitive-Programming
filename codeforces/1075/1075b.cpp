#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define maxn 200005
#define endl '\n'
#define pb push_back
ll cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	ll n,m;
	while(cin>>n>>m){
		vector<int>v;
		int ans[maxn]={};
		n+=m;
		f1(n){
			cin>>cont[i];
		}
		f1(n){
			int add;
			cin>>add;
			if(add)v.pb(i);
		}
		for(int i=1;i<v[0];i++){
			ans[0]++;
		}
		for(int i=v[v.size()-1]+1;i<=n;i++){
			ans[v.size()-1]++;
		}
		for(int i=0;i<v.size()-1;i++){
			for(int j=v[i]+1;j<v[i+1];j++){
				if(cont[j]-cont[v[i]]<=cont[v[i+1]]-cont[j]){
					ans[i]++;
				}
				else{
					ans[i+1]++;
				}
			}
		}
		for(int i=0;i<v.size();i++){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
}