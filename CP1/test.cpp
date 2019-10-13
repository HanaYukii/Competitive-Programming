#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
int check(ll n,ll i,int m){
	if(n%i!=m){
		return 0;
	}
	else{
		return check(n/i,i,m)+1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	while(cin >> n >> m){
		if(n==0&&m==0){
			cout<<2<<' '<<1<<endl;
			exit(0);
		}
		if(n==m){
			cout<<n+1<<' '<<1<<endl;
			exit(0);
		}
		ll num = n - m;
		int mx = 0;
		ll ans = 2;
		for(ll i=1;i*i<=num;i++){
			if(num%i)continue;
			ll t1 = i;
			ll t2 = num/i;
			//cout << t1 <<' '<< t2 << endl;
			if(t1 > m&& t1 > 1){
				int cur = check(n,t1,m);
				if(cur > mx){
					mx = cur;
					ans = t1;
				}
				else if(cur==mx && t1<ans){
					mx = cur;
					ans = t1;
				}
			}
			if(t2 > m && t2 > 1){
				int cur = check(n,t2,m);
				//cout<<t2<<' '<<cur<<endl;
				if(cur > mx){
					mx = cur;
					ans = t2;
				}
				else if(cur==mx && t2<ans){
					mx = cur;
					ans = t2;
				}
			}
		}
		cout << ans <<' ' << mx << endl;
	}
	
}