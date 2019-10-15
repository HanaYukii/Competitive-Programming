#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int lay[maxn];
ll odd[maxn];
ll even[maxn];
int L[maxn],R[maxn];
vector<int>g[maxn];
int cur;
ll v[maxn];
int n;
void dfs(int now,int pre){
	L[now] = R[now]=++cur;
	for(auto i:g[now]){
		if(i==pre)continue;
		lay[i] = lay[now] + 1;
		dfs(i,now);
		R[now] = max(R[now],R[i]);
	}
}
ll query(int x,int tp){
	ll ret = v[x];
	x = L[x];
	while(x){
		if(tp){
			ret += odd[x];
		}
		else{
			ret += even[x];
		}
		x -= (x) & (-x);
	}
	return ret;
}
void update(int x,ll val){
	int tp = lay[x] & 1;
	int LL = L[x];
	int RR = R[x];
	if(!tp)val = -val;
	while(LL<=n){
		odd[LL] += val;
		even[LL] -= val;
		LL += (LL) & (-LL);
	}
	while(RR<=n){
		odd[RR] -= val;
		even[RR] += val;
		RR += (RR) & (-RR);
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    while(cin >> n >> m){
    	f1(n)cin >> v[i];
	    f(n-1){
	    	int add1,add2;
	    	cin >> add1 >> add2;
	    	g[add1].pb(add2);
	    	g[add2].pb(add1);
	    }
	    cur = 0;
	    dfs(1,0);
	    f1(n)R[i]++;
	    while(m--){
	    	int op,tar;
	    	cin >> op >> tar;
	    	if(op==2){
	    		cout<<query(tar,lay[tar]&1)<<'\n';
	    	}
	    	else{
	    		int v;
	    		cin >> v;
	    		update(tar,v);
	    	}
	    }
	}
}