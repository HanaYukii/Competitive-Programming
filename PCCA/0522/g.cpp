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

int main()
{
	int n,k;
	while(cin >> n >> k){
		queue<int>q;
		int v[n+5]={};
		vector<int>g[n+5];
		int cont[n+5]={};
		f1(n){
			int add;
			cin >> add;
			cont[i]=add;
			if(add==i){
				q.push(add);
				v[add] = 1;
			}
			else{
				g[add].pb(i);
			}
		}
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(auto i:g[now]){
				if(!v[i]){
					q.push(i);
					v[i]=1;
				}
			}
		}
		int dp[k+5]={1};
		int ff=0,ans=0;
		f1(n){
			ff += v[i];
		}
		for(int i=1;i<=n;i++){
			if(v[i])continue;
			else{
				int cnt[n+5]={};
				int now=1;
				int pos=i;
				while(cnt[pos]==0){
					cnt[pos]=now++;
					pos=cont[pos];
				}
				int len=now-cnt[pos];
				//cout<<len<<endl;
				queue<int>q;
				int num=1;
				v[pos]=1;
				q.push(pos);
				while(!q.empty()){
					int fr=q.front();
					q.pop();

					for(auto j:g[fr]){
						//cout<<"here";
						if(!v[j]){
							num++;
							q.push(j);
							v[j]=1;
						}
					}
				}
				int tmp[k+5]={};
				fr(j,0,k+1){
					tmp[j]=dp[j];
				}
				//cout<<len<<' '<<num<<endl;
				for(int j=len;j<=num;j++){
					for(int l=k;l>=j;l--){
						if(tmp[l-j]){
							dp[l]=1;
							ans=max(ans,l);
						}

					}
				}
			}
		}
		cout <<min(ans+ff,k)<<endl;
	}
}