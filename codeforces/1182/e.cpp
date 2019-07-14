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
ll pm(ll x,ll p){
	ll ret = 1;
	ll now = x;
	while(p){
		if(p&1){
			ret *= now;
			ret %= mod;
		}
		now *= now;
		now %= mod;
		p >>= 1;
	}
	return ret;
}
ll extgcd(ll a, ll b, ll &x, ll &y){
    if (!b) return x = 1, y = 0, a;
    ll res = extgcd(b, a%b, y, x);
    return y -= a / b * x, res;
}
ll modInv(ll a, ll m){
    ll x, y, d = extgcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,f1,f2,f3,c;
	while(cin >> n >> f1 >> f2 >> f3 >> c){
		map<ll,int>p1,p2,p3;
		set<int>p;
		for(ll i=2;i<=sqrt(f1);i++){
			if(f1%i == 0){
				ll cnt = 0;
				while(f1%i == 0){
					cnt++;
					f1/=i;
				}
				p1[i] = cnt;
			}
		}
		if(f1){
			p1[f1]=1;
		}
		for(ll i=2;i<=sqrt(f2);i++){
			if(f2%i == 0){
				ll cnt = 0;
				while(f2%i == 0){
					cnt++;
					f2/=i;
				}
				p2[i] = cnt;
			}
		}
		if(f2){
			p2[f2]=1;
		}
		for(ll i=2;i<=sqrt(f3);i++){
			if(f3%i == 0){
				ll cnt = 0;
				while(f3%i == 0){
					cnt++;
					f3/=i;
				}
				p3[i] = cnt;
			}
		}
		if(f3){
			p3[f3]=1;
		}
		ll tmp = c;
		for(ll i=2;i<=sqrt(c);i++){
			if(c%i == 0){
				ll cnt = 0;
				while(c%i == 0){
					cnt++;
					c/=i;
				}
				p1[i] += cnt;
				p2[i] += cnt*2;
				p3[i] += cnt*3;
			}
		}
		if(c){
			p1[c] ++;
			p2[c] += 2;
			p3[c] += 3;
		}
		c = tmp;
		for(auto i:p1){
			p.insert(i.first);
		}
		for(auto i:p2){
			p.insert(i.first);
		}
		for(auto i:p3){
			p.insert(i.first);
		}
		ll mat[3][3] = {};
		mat[0][0] = mat[0][1] = mat[0][2] = mat[1][0] = mat[2][1] = 1;
		ll need = n-3;
		int sz=p.size();
		map<int,ll>ip;
		ll pmat[3][sz];
		ms(pmat);
		int nn=0;
		for(auto i:p){
			ip[nn] = i;
			pmat[2][nn] = p1[i];
			pmat[1][nn] = p2[i];
			pmat[0][nn++] = p3[i];
		}
		for(int i=0;i<sz;i++){
			//cout<<ip[i]<<' '<<pmat[0][i]<<endl;
		}
		while(need){
			if(need&1){
				ll nmat[3][sz];
				ms(nmat);
				for(int i = 0;i < 3 ; i++){
					for(int j=0 ;j< sz ;j++){
						for(int k=0;k<3;k++){
							nmat[i][j] += pmat[k][j] * mat[i][k];
							nmat[i][j] %= mod-1;
						}
					}
				}
				for(int i= 0 ; i < 3 ;i++){
					for(int j = 0 ;j < sz ; j++){
						pmat[i][j] = nmat[i][j]; 
					}
				}
			}
			ll nat[3][3];
			ms(nat);
			f(3){
				fr(j,0,3){
					fr(k,0,3){
						nat[i][j] += mat[i][k] * mat[k][j];
						nat[i][j] %= mod-1;
					}
				}
			}
			f(3){
				fr(j,0,3){
					mat[i][j] = nat[i][j];
					//cout<<mat[i][j]<<' ';
				}
				//cout << endl;
			}
			need >>= 1;
		}
		ll ans = 1;
		for(int i=0;i<sz;i++){
			//cout<<ip[i]<<' '<<pmat[0][i]<<endl;
		}
		for(int i=0;i<sz;i++){
			ans *= pm(ip[i],pmat[0][i]);
			ans %= mod;
		}
		//cout << ans << endl;
		ans *= modInv(pm(c, n), mod); 
		ans %= mod;
		cout << ans << endl;
	}
}