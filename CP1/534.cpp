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
ll read(){
    ll n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int t;
	t=read();
	while(t--){
		int n;
		ll r;
		n=read();
		r=read();
		ll cont[n+5] = {};
		vector<ll>st;
		set<int>id;
		unordered_map<ll,int>mp;
		ll mp2[n+5]={};
		f1(n){
			cont[i]=read();
			st.pb(cont[i]);
		}
		int idx=1;
		sort(st.bg,st.ed);
		for(auto i:st){
			mp2[idx]=i;
			mp[i]=idx++;
		}
		id.insert(mp[cont[1]]);
		for(int i=2;i<=n;i++){
			auto k=id.lower_bound(mp[cont[i]]);
			if(k==id.end()){
				int lb=*(--id.end());
				if(abs(mp2[lb]-cont[i])>r){
					id.insert(mp[cont[i]]);
				}
			}
			else if(k==id.begin()){
				int rb=*id.begin();
				if(abs(mp2[rb]-cont[i])>r){
					id.insert(mp[cont[i]]);
				}
			}
			else{
				int rb=*(k);
				int lb=*(--k);
				if(abs(mp2[rb]-cont[i])>r&&abs(mp2[lb]-cont[i])>r){
					id.insert(mp[cont[i]]);
				}
			}
		}
		printf("%u\n",id.size());
	}

}