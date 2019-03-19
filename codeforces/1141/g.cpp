#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ls(x) arr[x].child[0]
#define rs(x) arr[x].child[1]
vector<int>g[maxn];
map<pair<int,int>,int>cl;
void(dfs)
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	ll n;
	while(cin>>n>>k){
		int deg[n+5]={};
		set<pair<int,int> >st;
		f(n){
			int add1,add2;
			cin>>add1>>add2;
			g[add1].pb(add2);
			g[add2].pb(add1);
			deg[add1]++,deg[add2]++;
		}
		f1(n){
			st.insert({deg[i],i});
		}
		int cnt=0;
		for(auto i:st){
			cnt++;
			if(cnt>n-k&&i.first>2){
				ng.insert(i);
			}
		}
		dfs(1,0);
	}
}