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
const ll mod = 1e9+7;
int c[200005];
vector<int>g[200005];
vector<int>ans1,ans2;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		
		f1(n){
			c[i]=0;
			g[i].clear();
			ans1.clear();
			ans2.clear();
		}

		f(m){
			int add1,add2;
			cin >> add1 >> add2;
			g[add1].pb(add2);
			g[add2].pb(add1);

		}
		queue<int>q;
		c[1] = 1;
		ans1.pb(1);
		q.push(1);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			int cc=c[now];
			for(auto i:g[now]){
				if(!c[i]){
					if(cc==1){
						ans2.pb(i);
						c[i]=2;
					}
					else{
						ans1.pb(i);
						c[i]=1;
					}
					q.push(i);
				}
			}
		}
		if(ans1.size()<ans2.size()){
			cout<<ans1.size()<<'\n';
			for(auto i:ans1){
				cout<<i<<' ';
			}
			cout<<'\n';
		}
		else{
			cout<<ans2.size()<<'\n';
			for(auto i:ans2){
				cout<<i<<' ';
			}
			cout<<'\n';
		}
	}
}