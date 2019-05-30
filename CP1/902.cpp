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
	int t;
	cin >> t;
	while(t--){
		int n,z;
		cin >> n >> z;
		while(z--){
		int tp;
		cin >> tp;
		if(tp==2){
			ll x=1,y=1;
			ll k;
			cin >> k;
			k--;
			for(int i=n-1;i>=0;i--){
				if(k>=(1LL<<(i*2+1))){
					x += (1<<i);
				}
				k%=(1LL<<(i*2+1));
				//cout <<k<<endl;
				if(k>=(1LL<<(i*2))){
					y += (1<<i);
				}
				k%=(1LL<<(i*2));
				//cout << k << endl;
			}
			cout << x << ' '<<y<<endl;
		}
		else{
			int x,y;
			cin >> x >> y;
			x--,y--;
			ll ans = 1;
			for(int i=n-1;i>=0;i--){
				if(x>=(1<<i)&&y>=(1<<i)){
					ans += (1LL<<i)*(1LL<<i)*3;
				}
				else if(x>=(1<<i)){
					ans += (1LL<<i)*(1LL<<i)*2;
				}
				else if(y>=(1<<i)){
					ans += (1LL<<i)*(1LL<<i);
				}
				x%=(1<<i);
				y%=(1<<i);
			}
			cout << ans << endl;
		}
	}
	}
}