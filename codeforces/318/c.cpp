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
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll x,y,m;
	while(cin >> x >> y >> m){
		ll ans = 0;
		if(x>y){
			swap(x,y);
		}
		int cur = 0;
		if(x<=0&&y<=0&&max(x,y)<m){
			cout<<-1<<endl;
			exit(0);
		}
		while(max(x,y)<m&&cur<100000){
			if(x<0&&y>0){
				ans += -x/y;
				x = -(abs(x%y));
				//continue;
			}
			//cout << x <<' '<<y<<endl;
			x = x+y;
			if(x>y)swap(x,y);
			ans++;cur++;
		}
		if(cur==100000){
			cout<<-1<<endl;
		}
		else{
			cout << ans << endl;
		}
	}
}