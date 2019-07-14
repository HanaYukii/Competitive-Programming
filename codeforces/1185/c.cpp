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
	ll n,m;
	while(cin >> n >> m){
		multiset<ll>st;
		int ans[n+5] = {};
		ll cnt[105] = {};
		ll sum = 0;
		f(n){
			ll add;
			cin >> add;
			sum += add;
			ll need = sum - m;
			ll c = 0;
			//cout << need << '\n';
			if(need<=0){
				ans[i] = 0;
			}
			else{
				for(int j=100;j>=0;j--){
					if(cnt[j]==0)continue;
					//cout<<j<<' '<<need<<endl;
					if(need > cnt[j] * j){
						c += cnt[j];
						need -= cnt[j] * j;
					}
					else{
						c += need/j;
						if(need%j)c++;
						break;
					}
				}
				ans[i] = c;
			}
			cnt[add]++;
			
		}
		f(n){
			cout << ans[i]<<' ';
		}
		cout << endl;
	}

}