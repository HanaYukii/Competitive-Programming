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
int dp[255][255][255];
int nxt[26][100005];
int num[4];
vector<char>str[4];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,q;
	while(cin >>n >> q){
		string s;
		cin >> s;
		s=" "+s;
		f(26){
			nxt[i][n]=nxt[i][n+1]=n+1;
		}
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<26;j++){
				nxt[j][i]=nxt[j][i+1];
			}
			nxt[s[i+1]-'a'][i]=i+1;
		}
		while(q--){
			char c;
			cin >> c;
			if(c=='+'){
				int x;
				char add;
				cin >> x >> add;
				num[x]++;
				str[x].pb(add);
				for(int i=x==1?num[1]:0;i<=num[1];i++){
					for(int j=x==2?num[2]:0;j<=num[2];j++){
						for(int k=x==3?num[3]:0;k<=num[3];k++){
							dp[i][j][k] = n+1;
							if(i) dp[i][j][k] = min(dp[i][j][k],nxt[str[1][i-1]-'a'][dp[i-1][j][k]]);
							if(j) dp[i][j][k] = min(dp[i][j][k],nxt[str[2][j-1]-'a'][dp[i][j-1][k]]);
							if(k) dp[i][j][k] = min(dp[i][j][k],nxt[str[3][k-1]-'a'][dp[i][j][k-1]]);
						}
					}
				}
			}
			else{
				int k;
				cin >> k ;
				num[k]--;
				str[k].pop_back();
			}
			//cout<<dp[str[1].size()][str[2].size()][str[3].size()]<<endl;
			if(dp[num[1]][num[2]][num[3]]<=n){
				cout<<"YES"<<'\n';
			}
			else{
				cout<<"NO"<<'\n';
			}
		}
	}

}