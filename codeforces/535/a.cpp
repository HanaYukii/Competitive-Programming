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
vector<ll>v;
void dfs(ll cur,int cnt){
	if(cnt == 10){
		return ;
	}
	
	cur *= 10;
	v.pb(cur+7);
	dfs(cur+7,cnt+1);
	v.pb(cur+4);
	dfs(cur+4,cnt+1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	v.pb(0);
	dfs(0,0);
	sort(v.begin(),v.end());
	while(cin >> n){
		cout<<lower_bound(v.begin(),v.end(),n)-v.begin()<<endl;
	}
}