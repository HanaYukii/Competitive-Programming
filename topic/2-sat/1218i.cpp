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
	for(int i=0;i<4*n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=0;i<4*n;i+=2){
		//cout<<fa[i]<<' '<<fa[i+1]<<endl;
		if(fa[i]==fa[i+1])return 0;
		opp[fa[i]] = fa[i+1];
		opp[fa[i+1]] = fa[i];
	}
	return 1;
}
void build(){
	for(int i=0;i<4*n;i++){
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
	int cnt = 0;
	for (int i = 0; i < n*2; i++){
		if(c[fa[i*2]]==1)cnt++;
	}
	cout << cnt << '\n';
	for (int i = 0; i < n; i++){
		if(c[fa[i*2]]==1){
			cout<<"row"<<' '<<i<<'\n';
		}
	}
	for (int i = 0; i < n; i++){
		if(c[fa[(n+i)*2]]==1){
			cout<<"col"<<' '<<i<<'\n';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n){
		string s1[n],s2[n],ss;
		for (int i = 0; i < n; i++){
			cin >> s1[i];
		}
		for (int i = 0; i < n; i++){
			cin >> s2[i];
		}
		cin >> ss;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				int ch = 0;
				if(s1[i][j]!=s2[i][j])ch = 1;
				int chi = 0;
				if(ss[j]=='1'){
					chi = 1;
				}
				int chj = 0;
				if(ss[i]=='1'){
					chj = 1;
				}
				if(ch==1&&chi==0&&chj==0){
					cout<<-1<<endl;
					exit(0);
				}
				if(ch==1){
					if(chi==1&&chj==1){
						g[i*2].push_back((n+j)*2+1);
						g[i*2+1].push_back((n+j)*2);
						g[(n+j)*2+1].push_back(i*2);
						g[(n+j)*2].push_back(i*2+1);
					}
					else if(chi){
						g[i*2+1].push_back(i*2);
					}
					else{
						g[(n+j)*2+1].push_back((n+j)*2);
					}
				}
				else{
					if(chi==1&&chj==1){
						g[i*2].push_back((n+j)*2);
						g[(n+j)*2].push_back(i*2);
						g[i*2+1].push_back((n+j)*2+1);
						g[(n+j)*2+1].push_back(i*2+1);
					}
					else if(chi){
						g[i*2].push_back(i*2+1);
					}
					else if(chj){
						g[(n+j)*2].push_back((n+j)*2+1);
					}
				}
			}
		}
		if(check()){
			build();
			topo();
		}
		else{
			cout<<-1<<endl;
		}
	}
}