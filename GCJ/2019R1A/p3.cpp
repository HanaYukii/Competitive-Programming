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
#define bg begin()
#define ed end()
using namespace std;
int f;
int u[25][25],n,m;
vector<pair<int,int>>ans;
void dfs(int now,int x,int y,vector<pair<int,int>>p){
	if(f)return;
	if(now ==n*m){
		f=1;
		ans.clear();
		for(auto i:p){
			ans.pb(i);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(u[i][j])continue;
			if(j-i==y-x||j+i==y+x||j==y||i==x)continue;
			u[i][j] = 1;
			p.pb({i,j});
			dfs(now+1,i,j,p);
			p.pop_back();
			u[i][j] = 0;
		}
	}
}
int main()
{
	int t;
	cin >> t;
    for (int c = 1 ;c<=t;c++)
    {
        cin >> n >> m;
        vector<pair<int,int>>p;
        f=0;
        ms(u);
        dfs(0,-50,25,p);
        if(!ans.size()){
        	printf("Case #%d: IMPOSSIBLE\n",c);
        }
        else{
        	printf("Case #%d: POSSIBLE\n",c);
        	for(auto i:ans){
        		cout << i.first << ' '<< i.second << endl;
        	}
        }
        
    }
    return 0;
}
