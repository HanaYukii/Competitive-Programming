#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;


int main(void){
	ios_base::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		int cont[305]={};
		f(n)cin>>cont[i];
		vector<int>b[305];
		vector<pair<int,int>>e;
		f(m){
			int l,r;
			cin>>l>>r;
			l--,r--;
			e.pb({l,r});
			for(int j=l;j<=r;j++){
				b[j].pb(i);
			}
		}
		int Max=0;
		int mp=0;
		f(n){
			int now[305]={};
			fr(j,0,n){
				now[j]=cont[j];
			}
			for(auto j:b[i]){
				int l=e[j].first,r=e[j].second;
				for(int k=l;k<=r;k++){
					now[k]--;
				}
			}
			int mx=-1e7,mi=1e7;
			fr(j,0,n){
				mx=max(mx,now[j]);
				mi=min(mi,now[j]);
			}
			if(mx-mi>Max){
				Max=mx-mi;
				mp=i;
			}
		}
		cout<<Max<<endl;
		cout<<b[mp].size()<<endl;
		for(auto i:b[mp]){
			cout<<i+1<<' ';
		}
		cout<<endl;
	}
}