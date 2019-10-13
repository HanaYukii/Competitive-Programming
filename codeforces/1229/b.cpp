#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
vector<int>g[100005];
unordered_map<ll,ll>mp[100005];
ll v[100005];
ll ans;
void dfs(int now,int pre){
	mp[now][v[now]]++;
	for(auto i:g[now]){
		if(i==pre)continue;
		for(auto j:mp[now]){
			mp[i][__gcd(j.F,v[i])] += j.S;
		}
		dfs(i,now);
	}
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    f1(n){
    	cin >> v[i];
    }
    f(n-1){
    	int add1,add2;
    	cin >> add1 >> add2;
    	g[add1].pb(add2);
    	g[add2].pb(add1);
    }
    ans = 0;
    dfs(1,0);
    f1(n){
    	for(auto j:mp[i]){
    		ans += j.F * j.S % mod;
    		ans %= mod;
    	}
    }
    cout << ans << endl;
}