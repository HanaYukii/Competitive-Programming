#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define bg begin()
#define ed end()
#define pii pair<int,int>
int b[100005];
void update(int x , int d){
	while(x<100005){
		b[x] = max(b[x],d) ;
		x += (x)&(-x);
	}
}
int sum(int x){
	int ret = 0;
	while(x){
		ret = max(ret,b[x]);
		x -= x&(-x);
	}
	return ret;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		ms(b);
		int n;
		cin >> n;
		vector<pair<int,int> >v;
		f(n){
			int add1 , add2;
			cin >> add1 >> add2;
			v.pb({add1,add2});
		}	
		sort(v.begin(),v.end());
		vector<int>d;
		f(n){
			d.pb(v[i].second);
		}
		sort(d.begin(),d.end());
		d.erase(unique(d.begin(),d.end()),d.end());
		map<int,int>mp;
		for(int i=0;i<(int)d.size();i++){
			mp[d[i]]=i+1;
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			int now=mp[v[i].second];
			int mx=sum(now)+1;
			ans = max(ans,mx);
			update(now,mx);
		}
		cout << ans << endl;
	}
}