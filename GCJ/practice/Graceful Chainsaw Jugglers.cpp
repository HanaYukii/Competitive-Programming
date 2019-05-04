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

int main()
{
	int t;
	cin >> t;
    for (int c = 1 ;c <= t;c++)
    {
        int n,m;
        cin >> n >> m;
        int dp[505][505] = {-1};
        dp[0][0]=0;
        for(int i=0;i<=min((int)sqrt(n)+10,n);i++){
        	for(int j=0;j<=min((int)sqrt(m)+10,m);j++){
        		if(!i&&!j)continue;
        		for(int k=n;k>=i;k--){
        			for(int l=m;l>=j;l--){
        				if(dp[k-i][l-j]!=-1)
        					dp[k][l]=max(dp[k][l],dp[k-i][l-j]+1);
        			}
        		}
        	}
        }
        printf("Case #%d: %d\n",c,dp[n][m]);
    }
    return 0;
}
