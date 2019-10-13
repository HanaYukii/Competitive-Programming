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
const ll mod = 1e9+7;
int v[200005];
int nxt[200005];
ll ans;
int lef;
ll pm(int x){
	int ret = 1;
	int cur = 2;
	while(x){
		if(x & 1){
			ret *= cur;
			ret %= mod;
		}
		cur *= cur;
		cur %= mod;
		x >>= 1;
	}
	return ret;
}
void dfs(int cur){
	unordered_set<int>st;
	int cnt = 1;
	while(!v[cur]){
		v[cur] = cnt;
		cnt++;
		st.insert(cur);
		cur = nxt[cur];
		
	}
	if(st.find(cur)!=st.end()){
		int add = cnt - v[cur];
		ans *= pm(add)-2;
		lef -= add;
		ans %= mod;
		//cout<<add<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		lef = n;
		ms(v);
		ans = 1;
		f1(n){
			cin >> nxt[i];
		}
		f1(n){
			if(!v[i]){
				dfs(i);
			}
		}
		ans *= pm(lef);
		ans %= mod;
		cout << ans << endl;
	}
}