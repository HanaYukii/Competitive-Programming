#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;


int dp[105][105];
int b[105][105];
int h,v,n,m,p;

int main(){
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		cin >> n >>m >> h >> v;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=0;
				b[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			string add;
			cin >> add;
			for(int j=1;j<=m;j++){
				if(add[j-1]=='@')b[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]){
					dp[i][j]=dp[i][j-1]+1;
				}
				else{
					dp[i][j]=dp[i][j-1];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]+=dp[i-1][j];
			}
		}
		if(dp[n][m]%((h+1)*(v+1))){
			printf("Case #%d: IMPOSSIBLE\n",c);
		}
		else{
			int f=0;
			p=dp[n][m]/((h+1)*(v+1));
			vector<int>v1,v2;

			for(int i=1;i<=n;i++){
				if(dp[i][m]==((int)v1.size()+1)*p*(v+1)){
					v1.push_back(i);
					if(v1.size()==h+1)break;
				}
			}
			for(int i=1;i<=m;i++){
				if(dp[n][i]==((int)v2.size()+1)*p*(h+1)){
					v2.push_back(i);
					if(v2.size()==v+1)break;
				}
			}
			if((int)v1.size()!=h+1||(int)v2.size()!=v+1)f=1;
			for(int i=0;i<(int)v1.size();i++){
				for(int j=0;j<(int)v2.size();j++){
					if(dp[v1[i]][v2[j]]!=(i+1)*(j+1)*p)f=1;
				}
			}
			if(f)
			printf("Case #%d: IMPOSSIBLE\n",c);
			else
			printf("Case #%d: POSSIBLE\n",c);
		}
		
	}
}