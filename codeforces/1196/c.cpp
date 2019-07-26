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
#define F first
#define S second
const ll mod = 998244353;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int mix=-1e5,miy=-1e5,mxx=1e5,mxy=1e5;
		f(n){
			int x,y;
			cin >> x >> y;
			int v[4];
			fr(j,0,4){
				cin >> v[j];
			}
			if(!v[0]){
				mix = max(mix,x);
			}
			if(!v[1]){
				mxy = min(mxy,y);
			}
			if(!v[2]){
				mxx = min(mxx,x);
			}
			if(!v[3]){
				miy = max(miy,y);
			}
		}
		if(miy<=mxy&&mix<=mxx){
			cout<<1<<' '<<mix<<' '<<miy<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
	}
}