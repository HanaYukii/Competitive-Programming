#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
vector<pair<int,int> >g[105];
int dp[105][105][30];
int solve(int f,int s,int pre){
	if(dp[f][s][pre])return dp[f][s][pre];
	int mi = 1;
	for(auto i:g[f]){
		if(i.S>=pre){
			mi = min(mi,solve(s,i.F,i.S));
		}
	}
	if(mi==1){
		return dp[f][s][pre] = -1;
	}
	else{
		return dp[f][s][pre] = 1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		f(m){
			int add1,add2;
			char c;
			cin >> add1 >> add2 >> c;
			g[add1].pb({add2,c-'a'});
		}
		f1(n){
			fr(j,1,n+1){
				if(solve(i,j,0)==1){
					cout<<"A";
				}
				else{
					cout<<"B";
				}
			}
			cout << endl;
		}
	}
}