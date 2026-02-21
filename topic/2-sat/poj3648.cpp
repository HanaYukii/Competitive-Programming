#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

using namespace std;
const int mod = 1e9+7;
const int MAXN = 66;
vector<int>g[MAXN]; 
vector<int>rev[MAXN]; 
stack<int>st;  
int n,m,scc,index;  
int low[MAXN],dfn[MAXN],instack[MAXN],fa[MAXN];  
int ans[MAXN];
int in[MAXN];
int opp[MAXN],c[MAXN];
int toidx(string s){
	int n=s.size();
	char c = s[n-1];
	s=s.substr(0,n-1);
	int ret = 0;
	for(int i=0;i<(int)s.size();i++){
		int k = s[i];
		ret *= 10;
		ret += k-'0';
	}
	ret *= 2;
	if(c=='h'){
		ret ++;
	}
	return ret;
}
void init(){
	scc = index = 0;
	while(!st.empty())st.pop();
	for(int i=0;i<MAXN;i++)g[i].clear(),rev[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));
	memset(low,0,sizeof(low));
	memset(ans,0,sizeof(ans));
	memset(fa,0,sizeof(fa));

}
void tarjan(int now){
	dfn[now] = low[now] = ++index;
	instack[now] = 1;
	st.push(now);
	for(int k=0;k<(int)g[now].size();k++){
		int i = g[now][k];
		if(!dfn[i]){
			tarjan(i);
			low[now] = min(low[now],low[i]);
		}
		else if(instack[i]){
			low[now] = min(low[now],dfn[i]);
		}
	}
	if(dfn[now] == low[now]){
		scc++;
		while(1){
			int cur = st.top();
			st.pop();
			instack[cur] = 0;
			fa[cur] = scc;
			if(cur == now)break;
		}
	}
}
bool check(){
	for(int i=0;i<2*n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=0;i<2*n;i+=2){
		if(fa[i]==fa[i+1])return 0;
		opp[fa[i]] = fa[i+1];
		opp[fa[i+1]] = fa[i];
	}
	return 1;
}
void build(){
	for (int i = 0; i < 2*n; i++){
		int x = fa[i];
		for(int j=0;j<(int)g[i].size();j++){
			int y = fa[g[i][j]];
			if(x!=y){
				rev[y].push_back(x);
				in[x]++;
			}
		}
	}
}
void topo(){
	memset(c,0,sizeof(c));
	queue<int>q;
	for (int i = 1; i <= scc; i++){
		if(!in[i])q.push(i);
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(!c[now]){
			c[now] = 1;
			c[opp[now]] = 2;
		}
		for(int i = 0 ; i <(int)rev[now].size() ; i++){
			int nxt = rev[now][i];
			in[nxt]--;
			if(!in[nxt]){
				q.push(nxt);
			}
		}
	}
	for (int i = 1; i <= n-1; i++){
		if(c[fa[i*2]]==1){
			cout<<i<<'w'<<' ';
		}
		else{
			cout<<i<<'h'<<' ';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m && n){
		init();
		for (int i = 0; i < m; i++){
			string s1,s2;
			cin >> s1 >> s2;
			int add1 = toidx(s1);
			int add2 = toidx(s2);
			if(add1>add2){
				swap(add1,add2);
			}
			if(add1 == 0){

			}
			else if(add1 == 1){
				g[add2^1].push_back(add2);
			}
			else{
				g[add1^1].push_back(add2);
				g[add2^1].push_back(add1);
			}
		}
		if(check()){
			build();
			topo();
		}
		else{
			cout<<"bad luck"<<'\n';
		}
	}
}