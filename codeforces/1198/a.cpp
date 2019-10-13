#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin >> n >> k){
		k *= 8;
		k /= n;
		map<int,int>mp;
		f(n){
			int add;
			cin >> add;
			mp[add]++;
		}
		vector<int>v;
		for(auto i:mp){
			v.pb(i.second);
		}
		if(k>20)k = 20;
		k = 1<<k;
		if(k>v.size()){
			k = v.size();
		}
		int sz = v.size();
		int pre[sz+5] = {};
		for(int i=1;i<=sz;i++){
			pre[i] = pre[i-1] + v[i-1];
		}
		int mx = 0;
		for(int i=k;i<=sz;i++){
			mx = max(mx,pre[i]-pre[i-k]);
		}
		cout << n - mx << endl;
	}
}