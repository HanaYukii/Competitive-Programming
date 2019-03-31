#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
int bit[maxn];
void update(int x){
	while(x < maxn ){
		bit[x]++;
		x+=(x & (-x) );
	}
}
ll sum(int x){
	ll ret = 0;
	while(x){
		ret += bit[x];
		x -= (x&(-x));
	}
	return ret;
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n , k;
	while(cin >> n >> k){
		if(k==-1){
			map<ll,int>mp;
			mp[0] = 1;
			ll now = 0;
			ll ans = 0;
			f(n){
				ll add;
				cin >> add;
				now += add;
				ans += mp[now-1];
				ans += mp[now+1];
				mp[now]++;
			}
			cout << ans << endl;
		}
		else if(k != 1){
			map<ll,int>mp;
			mp[0] = 1;
			ll now = 0;
			ll ans = 0;
			f(n){
				ll add;
				cin >> add;
				now += add;
				ll minus = 1;
				while(abs(minus)<(ll)1e15){
					if(mp.find(now-minus)!=mp.end()){
						ans += mp[now-minus];
					}
					minus *= k;
				}
				mp[now]++;
			}
			cout << ans << endl;
		}
		else{
			map<ll,int>mp;
			mp[0] = 1;
			ll now = 0;
			ll ans = 0;
			f(n){
				ll add;
				cin >> add;
				now += add;
				ans += mp[now-1];
				mp[now]++;
			}
			cout << ans << endl;

		}
	}
}