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
vector<pair<int,int> >g[maxn];
map<pair<int,int>,int>mp;
set<int>ng;
int mx;
int deg[maxn+5]={};
void dfs(int now,int pre,int pc){
	for(auto &i:g[now]){
		if(i.first!=pre){
			i.second=(pc^1)+1;
			dfs(i.first,now,pc^1);
		}
	}
}
void dfs2(int now,int pre,int pc){
	if(ng.find(now)==ng.end()){
		mx=max(mx,deg[now]);
		set<int>st;
		f1(deg[now]){
			st.insert(i);
		}
		st.erase(pc);
		for(auto &i:g[now]){
			if(i.first!=pre){
				if(st.find(i.second)!=st.end()){
					st.erase(i.second);
					dfs2(i.first,now,i.second);
				}
				else{
					i.second=*(st.begin());
					st.erase(i.second);
					dfs2(i.first,now,i.second);
				}
			}
		}
	}
	else{
		for(auto &i:g[now]){
			if(i.first!=pre){
				i.second=max(1,pc);
				dfs2(i.first,now,i.second);
			}
		}
	}
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int n,k;
	while(cin>>n>>k){
		mx=1;
		
		set<pair<int,int> >st;
		vector<pair<int,int> >v;
		f(n-1){
			int add1,add2;
			cin>>add1>>add2;
			v.pb({add1,add2});
			g[add1].pb({add2,0});
			g[add2].pb({add1,0});
			deg[add1]++,deg[add2]++;
		}
		f1(n){
			st.insert({deg[i],i});
		}
		int cnt=0;
		for(auto i:st){
			cnt++;
			if(cnt>n-k&&i.first>=2){
				ng.insert(i.second);
			}
		}
		dfs(1,0,1);
		dfs2(1,0,0);
		f1(n){
			for(auto j:g[i]){
				mp[{i,j.first}]=j.second;
			}
		}
		cout<<mx<<endl;
		for(auto i:v){
			cout<<max(mp[{i.first,i.second}],mp[{i.second,i.first}])<<' ';
		}
		cout<<endl;
	}
}