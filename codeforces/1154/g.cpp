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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >>n){
		int pos[10000005][2]={};
		int cont[n+5]={};
		f(n){
			cin>>cont[i];
			if(!pos[cont[i]][0])pos[cont[i]][0]=i+1;
			else pos[cont[i]][1]=i+1;
		}
		ll n1,n2,Min=1e18;
		f1(1e7){
			vector<ll>v;
			for(ll j=i;j<=1e7;j+=i){
				if(pos[j][0])v.pb(j);
				if(pos[j][1])v.pb(j);
				if(v.size()>=2){
					if((v[0]*v[1])/i<Min){
						Min=(v[0]*v[1])/i;
						n1=v[0];
						n2=v[1];

					}
				break;
				}
			}
			
		}
		int p1,p2;
		if(n1==n2){
			p1=pos[n1][0];
			p2=pos[n1][1];
		}
		else{
			p1=pos[n1][0];
			p2=pos[n2][0];
		}
		if(p1>p2){
			swap(p1,p2);
		}
		cout<<p1<<' '<<p2<<endl;
	}

}