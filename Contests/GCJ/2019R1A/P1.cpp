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
struct t{
	int cnt;
	unordered_map<char,int>dec;
	int ans;
}dp[50030];
void dfs(int now){
	int sum=0;
	for(auto i:dp[now].dec){
		dfs(i.second);
		sum += dp[i.second].ans;
	}
	if(dp[now].cnt-(sum*2)>=2){
		sum++;
	}
	dp[now].ans=sum;
}
int main()
{
	int t;
	cin >> t;
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
    for (int c = 1 ;c<=t;c++)
    {
        f(50005){
        	dp[i].cnt=0;
        	dp[i].dec.clear();
        	dp[i].ans=0;
        }
        int n,idx=1;
        cin >> n;
        f(n){
        	string s;
        	cin >> s;
        	reverse(s.begin(),s.end());
        	int now=0;
        	for(auto i:s){
        		if(dp[now].dec.find(i)==dp[now].dec.end()){
        			dp[now].dec[i]=idx;
        			now=idx;
        			dp[idx++].cnt=1;
        		}
        		else{
        			now=dp[now].dec[i];
        			dp[now].cnt++;
        		}
        	}
        	
        }
        dfs(0);
        printf ( "Case #%d: %d\n" , c,dp[0].ans*2 );
    }
    return 0;
}
