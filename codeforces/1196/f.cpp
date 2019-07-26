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
const int mod = 1e9+7;
struct e
{
	int x,y;
	ll w;
};
bool cmp(e x,e y){
	return x.w < y.w;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	while(cin >> n >> m >> k){
		vector<e>v;
		f(m){
			int add1,add2;
			ll add3;
			cin >> add1 >> add2 >> add3;
			v.pb({add1,add2,add3});
		}
		sort(v.begin(),v.end(),cmp);
		map<int,int>mp;
		int cur = 1;
		ll dist[min(m,k)*2+5][min(m,k)*2+5] = {};
 
		f(min(m,k)){
			int x = v[i].x;
			int y = v[i].y;
			if(mp.find(x) == mp.end()){
				mp[x] = cur++;
			}
			if(mp.find(y) == mp.end()){
				mp[y] = cur++;
			}
			dist[mp[x]][mp[y]] = dist[mp[y]][mp[x]] = v[i].w;
		}
		f1(cur-1){
			fr(j,1,cur){
				if(dist[i][j] == 0 && i != j){
					dist[i][j] = 1e18;
				}
			}
		}
		for(int k = 1 ; k < cur ; k++){
			for(int i = 1 ; i < cur ; i++){
				for(int  j = 1 ; j < cur ; j++){
					dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]); 
				}
			}
		}
		vector<ll>num;
		f1(cur-1){
			fr(j,1,i){
				num.pb(dist[i][j]);
			}
		}
		sort(num.begin(),num.end());
		cout<<num[k-1]<<endl;
	}		
}