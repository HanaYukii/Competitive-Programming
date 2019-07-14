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
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll k,n,a,b;
		cin >> k >> n >> a >> b;
		if(b*n>=k){
			cout<<-1<<'\n';
		}
		else{
			ll can = 0;
			for(ll i=1LL<<32;i;i>>=1){
				if(can+i>n)continue;
				ll now = can+i;
				if(now * a + (n-now)*b < k){
					can = now;
				}
			}
			cout << can << '\n';
		}
	}
}