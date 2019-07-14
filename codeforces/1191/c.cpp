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
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,q;
	while(cin >> n >> m >> q){
		vector<ll>v(m);
		f(m){
			cin >> v[i];
		}
		int pos = 0;
		ll mod = 1;
		int ans = 0;
		while(pos!=m){
			ll st = v[pos]/q*q+mod;
			if(st>v[pos])st-=q;
			ll ed = st + q-1;
			//cout<<st<<' '
			while(pos!=m){
				int num = upper_bound(v.begin(),v.end(),ed)-v.begin()-pos;
				mod += num;
				mod %= q;
				ans++;
				pos += num;
				ed += num;
				//cout<<num<<' '<<st<<' '<<ed<<endl;
				if(upper_bound(v.begin(),v.end(),ed)-v.begin()==pos)break;
			}
		}
		cout << ans << endl;
	}
}