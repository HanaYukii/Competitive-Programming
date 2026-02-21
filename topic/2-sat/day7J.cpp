#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
const int MAXN = 8005;
vector<int>g[MAXN]; 
vector<int>rev[MAXN]; 
stack<int>st;  
int n,m,scc,idx;  
int low[MAXN],dfn[MAXN],instack[MAXN],fa[MAXN];  
int ans[MAXN];
int in[MAXN];
int opp[MAXN],c[MAXN];
int nd[MAXN];
void tarjan(int now){
	dfn[now] = low[now] = ++idx;
	instack[now] = 1;
	st.push(now);
	for(auto i:g[now]){
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
	for(int i=4;i<=4*n+3;i++){
		if(!nd[i/4])continue;
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=4;i<4*n+3;i+=2){
		if(!nd[i/4])continue;
		opp[fa[i]] = fa[i+1];
		opp[fa[i+1]] = fa[i];
	}
	return 1;
}
void build(){
	for(int i=4;i<=4*n+3;i++){
		if(!nd[n/4])continue;
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
	for(int i=1;i<=n;i++){
		if(!nd[i])cout<<'x';
		else{
			if(c[fa[i*4]]==1){
				cout<<'-';
			}
			else if(c[fa[i*4+2]]==1){
				cout<<'+';
			}
			else{
				cout<<'=';
			}
		}
	}
	cout << endl;
}
struct op
{
	int add1,add2;
	string tp;
};
vector<op>v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m && n){
		for (int i = 0; i < m; i++){
			int add1,add2;
			string s;
			cin >> add1 >> add2 >> s;
			if(s!="x"){
				nd[add1] = nd[add2] = 1;
				v.push_back({add1,add2,s});
			}
			
		}
		for(auto i:v){
			int add1 = i.add1;
			int add2 = i.add2;
			//  *4 + 0 = 0.5 true
			//  *4 + 1 = 0.5 false
			//  *4 + 2 = 2 true
			//  *4 + 3 = 2 false
			string tp = i.tp;
			if(tp=="+"){
				g[add1*4].push_back(add1*4+1);
				g[add2*4].push_back(add2*4+1);
				g[add1*4+3].push_back(add2*4+2);
				g[add2*4+3].push_back(add1*4+2);
			}
			else if(tp=="-"){
				g[add1*4+2].push_back(add1*4+3);
				g[add2*4+2].push_back(add2*4+3);
				g[add1*4+1].push_back(add2*4);
				g[add2*4+1].push_back(add1*4);
			}
			else{
				g[add1*4].push_back(add2*4+2);
				g[add2*4].push_back(add1*4+2);
				g[add1*4+2].push_back(add2*4);
				g[add2*4+2].push_back(add1*4);
				g[add1*4+1].push_back(add2*4+3);
				g[add2*4+1].push_back(add1*4+3);
				g[add1*4+3].push_back(add2*4+1);
				g[add2*4+3].push_back(add1*4+1);
			}
		}
		//  *4 + 0 = 0.5 true
		//  *4 + 1 = 0.5 false
		//  *4 + 2 = 2 true
		//  *4 + 3 = 2 false
		for (int i = 1; i <= n; i++){
			if(!nd[i])continue;
			g[i*4].push_back(i*4+3);
			g[i*4+2].push_back(i*4+1);
		}
		if(check()){
			build();
			topo();
		}
	}
}