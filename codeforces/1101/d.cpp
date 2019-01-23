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

int vis[200005],vis2[200005];
int cont[200005];

int cnt[200005];
vector<int>g[200005];
vector<int>pr;
vector<int>b[200005];
int md;
int mp;
void dfs(int now,int d,int p){
	if(d>md){
		md=d;
		mp=now;
	}
	for(auto i:g[now]){
		if(vis[i]!=p&&cont[i]%p==0){
			vis[i]=p;
			dfs(i,d+1,p);
		}
	}
}
int dfs2(int now,int p){
	int ret=1;
	for(auto i:g[now]){
		if(vis2[i]!=p&&cont[i]%p==0){
			vis2[i]=p;
			ret=max(ret,dfs2(i,p)+1);
		}
	}
	return ret;
}
int main(void){
	ios_base::sync_with_stdio(false);
	int n;
	while(cin>>n){
		ms(cnt);
		pr.pb(2);
		for(int i=3;i<=200000;i+=2){
			int f=0;
			for(int j=2;i<=sqrt(i);j++){
				if(i%j==0){
					f=1;
					break;
				}
			}
			if(!f){
				pr.pb(i);
			}
		}
		int z=0;
		f1(n){
			cin>>cont[i];
			int tp=cont[i];
			if(cont[i]>1){
				z=1;
			}
			for(auto j:pr){
				if(cont[i]%j==0){
					b[j].pb(i);
					while(cont[i]%j==0){
						cont[i]/=j;
					}
				}
				if(cont[i]<j*j)
					break;
			}
			if(cont[i]>1){
				b[cont[i]].pb(i);
			}
			cont[i]=tp;
		}
		if(!z){
			cout<<0<<endl;
			exit(0);
		}
		else{
			int mx=1;
			int add1,add2;
			for(int i=0;i<n-1;i++){
				cin>>add1>>add2;
				g[add1].pb(add2);
				g[add2].pb(add1);
					
			}
			for(auto p:pr){
				if(!b[p].size())
					continue;	
				//ms(vis);
				//ms(vis2);
				for(auto i:b[p]){

					if(vis[i]!=p){
						vis[i]=p;
						md=0;
						mp=i;
						dfs(i,0,p);
						vis2[mp]=p;
						mx=max(dfs2(mp,p),mx);
					}
				}
				
			}
			cout<<mx<<endl;
		}
	}

}