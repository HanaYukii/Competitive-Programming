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
vector<pii>v;
int f;
void dfs(int now,int n1,int n2){
	if(now==v.size()){
		f=1;
		return ;
	}
	if(n1==0){
		dfs(now+1,v[now].first,0);
		dfs(now+1,v[now].second,0);
	}
	else if((v[now].first!=n1&&v[now].second!=n1)&&(v[now].first!=n2&&v[now].second!=n2)){
		if(n2)return;
		dfs(now+1,n1,v[now].first);
		dfs(now+1,n1,v[now].second);
	}
	else{
		dfs(now+1,n1,n2);
	}
}
int main(){
	int n,k;
	while(cin >> k >> n){
		v.clear();
		f(n){
			int add1,add2;
			cin >> add1 >> add2;
			if(add1>add2)swap(add1,add2);
			v.pb({add1,add2});
		}
		f=0;
		dfs(0,0,0);
		cout<<(f?"YES":"NO")<<endl;
	}
}