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
int cont[200005],last[200005];
int pos[200005];
int dp[200005][20];
int start[200005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,q;
	while(cin >> n >> m >> q){
		
		ms(start);
		ms(pos);
		ms(dp);
		ms(last);
		f(n){
			cin >> cont[i];
		}
		f(n){
			last[cont[i]]=cont[((i-1)+n)%n];
		}
		for(int i=1;i<=m;i++){
			int add;
			cin >> add;
			if(pos[last[add]]!=0){
				dp[i][0] = pos[last[add]];
			}
			//cout<<pos[last[add]]<<endl;
			pos[add]=i;
		}

		for(int i=1;i<20;i++){
			for(int j=1;j<=m;j++){
				dp[j][i]=dp[dp[j][i-1]][i-1];
			}
		}
		for(int i=1;i<=m;i++){
			int need=n-1;
			int now=i;
			for(int j=19;j>=0;j--){
				if(need >= (1<<j)){
					now=dp[now][j];
					need -= (1<<j);
				}
			}
			start[i]=now;
		}
		f1(m){
			start[i]=max(start[i],start[i-1]);
		}
		while(q--){
			int a,b;
			cin >> a >> b;
			if(start[b]>=a&&start[b]!=0){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		cout<<endl;
	}
}