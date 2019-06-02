#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
#define maxn 500

int main() {
	ll n,m;
	while(cin >> n >> m){
		vector<pair<ll,ll> >v(n+5);
		ll mx = 0;
		f(n){
			cin >> v[i].first;
			mx = max(mx,v[i].first);
		}
		f(n){
			cin >> v[i].second;
		}
		ll cnt=0;
		for(int i=0;i<n;i++){
			cnt += (v[i].first - 1 - 1 )/v[i].second +1;
		}
		if(cnt <= m){
			ll sum = 0 ;
			for(int i=0;i<n;i++){
				ll cnt = (v[i].first - 1 - 1 )/v[i].second +1;
				ll low = v[i].first-(cnt-1)*v[i].second;
				ll up = v[i].first;
				// << cnt <<' '<<low<<' '<<up<<endl;
				sum += (low + up)*cnt /2;
			}
			sum += m-cnt;
			cout << sum <<endl;
			exit(0);
		}
		ll mi = 0;
		for(ll i=1LL<<35;i;i>>=1){
			ll now = mx-i-mi;
			if(now<=1)continue;
			ll cnt=0;
			for(int j=0;j<n;j++){
                if (v[j].first <= now)
                    continue;
				cnt += (v[j].first - now - 1 )/v[j].second +1;
			}
			if(cnt<m){
				mi += i;
			}
		}
		mi=mx-mi;
		cnt=0;
		for(int i=0;i<n;i++){
            if (mi >= v[i].first)
                continue;
			cnt += (v[i].first - mi - 1 )/v[i].second +1;
		}
		ll sum = 0 ;
		for(int i=0;i<n;i++){
            if (mi >= v[i].first)
                continue;
			ll cnt = (v[i].first - 1 - mi )/v[i].second +1;
			ll low = v[i].first-(cnt-1)*v[i].second;
			ll up = v[i].first;
			//cout << cnt <<' '<<low<<' '<<up<<endl;
			sum += (low + up)*cnt /2;
		}
		sum += (m-cnt)*mi;
		cout << sum <<endl;
	}
}