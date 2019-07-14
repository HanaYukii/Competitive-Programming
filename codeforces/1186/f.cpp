#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int maxn = 1000005;
int u[maxn];
int cur[maxn];
int need[maxn];
vector<pair<int,int> >e;
vector<int>g[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	while(cin >> n >> m){
		int goal = (n+m+1)/2;
		f(m){
			int add1,add2;
			cin >> add1 >> add2;
			e.pb({add1,add2});
		}
		
		again:
		f1(n)cur[i]=0;
		random_shuffle(e.begin(),e.end());
		f1(n){
			g[i].clear();
		}
		f(m){
			u[i] = 0;
			g[e[i].first].pb(i);
			g[e[i].second].pb(i);
		}
		f1(n){
			need[i] = (g[i].size()+1)/2;
		}
		for(int i=0;i<m;i++){
			int f=e[i].first;
			int s=e[i].second;
			if(cur[f]<need[f]&&cur[s]<need[s]){
				u[i] = 1;
				cur[f]++;
				cur[s]++;
			}
		}
		f1(n){
			int dif = need[i] - cur[i];
			for(int j=0;j<g[i].size()&&dif;j++){
				if(!u[g[i][j]]){
					u[g[i][j]]=1;
					dif--;
				}
			}
		}
		for(int i=0;i<m;i++){
			int f=e[i].first;
			int s=e[i].second;
			if(cur[f]-1>=need[f]&&cur[s]-1>=need[s]){
				u[i] = 0;
				cur[f]--;
				cur[s]--;
			}
		}
		int cnt = 0;
		for(int i=0;i<m;i++){
			if(u[i])cnt++;
		}
		if(cnt>goal)goto again;
		cout<<cnt<<'\n';
		for(int i=0;i<m;i++){
			if(!u[i])continue;
			int f=e[i].first;
			int s=e[i].second;
			cout<<f<<' '<<s<<'\n';
		}
		cout<<endl;
	}
}