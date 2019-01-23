#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
int vis[1005][1005];
struct pos{
	int x,y,p;
};
queue<pos>q[10];
int sp[10];
int main(void){
	ios_base::sync_with_stdio(false);
	int n,m,p;
	while(cin>>n>>m>>p){
		int sum[10]={};	
		f1(p){
			cin>>sp[i];
		}
		f1(n){
			string s;
			cin>>s;
			fr(j,1,m+1){
				if(s[j-1]>='1'&&s[j-1]<='9'){
					pos add;
					add.x=i;add.y=j;
					add.p=0;
					q[s[j-1]-'0'].push(add);
					vis[i][j]=1;
					sum[s[j-1]-'0']++;
				}
				else if(s[j-1]=='#'){
					vis[i][j]=1;
				}
			}
		}
		int rd=1;
		while(1){
			int f=0;
			for(int i=1;i<=p;i++){
				while(!q[i].empty()&&q[i].front().p!=sp[i]*rd){
					pos now=q[i].front();
					q[i].pop();
					if(!vis[now.x][now.y+1]&&now.y!=m){
						f=1;
						sum[i]++;
						vis[now.x][now.y+1]=1;
						pos add;
						add.x=now.x;
						add.y=now.y+1;
						add.p=now.p+1;
						q[i].push(add);
					}
					if(!vis[now.x][now.y-1]&&now.y!=1){
						f=1;
						sum[i]++;
						vis[now.x][now.y-1]=1;
						pos add;
						add.x=now.x;
						add.y=now.y-1;
						add.p=now.p+1;
						q[i].push(add);
					}
					if(!vis[now.x+1][now.y]&&now.x!=n){
						f=1;
						sum[i]++;
						vis[now.x+1][now.y]=1;
						pos add;
						add.x=now.x+1;
						add.y=now.y;
						add.p=now.p+1;
						q[i].push(add);
					}
					if(!vis[now.x-1][now.y]&&now.x!=1){
						f=1;
						sum[i]++;
						vis[now.x-1][now.y]=1;
						pos add;
						add.x=now.x-1;
						add.y=now.y;
						add.p=now.p+1;
						q[i].push(add);
					}
				}
			}
			rd++;
			if(!f)
				break;
		}
		f1(p){
			cout<<sum[i]<<' ';
		}
		cout<<endl;
	}
}