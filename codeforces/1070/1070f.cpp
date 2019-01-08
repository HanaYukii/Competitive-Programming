#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;
struct c{
	int type;
	ll num;
}cont[maxn];
bool cmp(c x,c y){
	return x.num>y.num;
}
int main(){
	int n,m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n){
		ll ans=0;
		int l=0,r=0;
		vector<int>c[3];
		f(n){
			int add1,add2;
			cin>>add1>>add2;
			if(add1==11){
				ans+=add2;
				l++,r++;
			}
			else if(add1==10){
				c[0].pb(add2);
			}
			else if(add1==1){
				c[1].pb(add2);
			}
			else{
				c[2].pb(add2);
			}
		}
		sort(c[0].begin(),c[0].end());
		sort(c[1].begin(),c[1].end());
		sort(c[2].begin(),c[2].end());
		int Min=min(c[0].size(),c[1].size());
		int n0=c[0].size()-1,n1=c[1].size()-1;
		int tt=Min;
		while(tt--){
			ans+=c[0][n0--];
			ans+=c[1][n1--];
		}
		int cnt=c[0].size()-Min+c[1].size()-Min+c[2].size();
		int now=0;
		for(int i=0;i<c[0].size()-Min;i++){
			cont[now].type=1;
			cont[now++].num=c[0][i];
		}
		for(int i=0;i<c[1].size()-Min;i++){
			cont[now].type=2;
			cont[now++].num=c[1][i];
		}
		for(int i=0;i<c[2].size();i++){
			cont[now].type=3;
			cont[now++].num=c[2][i];
		}
		sort(cont,cont+cnt,cmp);
		for(int i=0;i<cnt;i++){
			if(cont[i].type==1){
				if(r){
					r--;
					ans+=cont[i].num;
				}
			}
			else if(cont[i].type==2){
				if(l){
					l--;
					ans+=cont[i].num;
				}
			}
			else{
				if(l&&r){
					l--,r--;
					ans+=cont[i].num;
				}
			}
		}
		cout<<ans<<endl;
	}	
}