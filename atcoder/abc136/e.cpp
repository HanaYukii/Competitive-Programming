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
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin >> n >> k){
		int cont[n+5] = {};
		int sum = 0;
		f(n){
			cin >> cont[i];
			sum += cont[i];
		}	
		vector<int>fac;
		for(int i = 1 ; i <= sqrt(sum) ; i++){
			if(sum%i)continue;
			if(i * i == sum){
				fac.pb(i);
			}
			else{
				fac.pb(i);
				fac.pb(sum/i);
			}
		}
		sort(fac.begin(),fac.end());
		reverse(fac.begin(),fac.end());
		for(auto i:fac){
			vector<int>rem;
			int tot=0;
			int u = 0;
			fr(j,0,n){
				rem.pb(cont[j]%i);
				tot += i - (cont[j]%i);
			}
			sort(rem.begin(),rem.end());
			for(auto j:rem){
				u += j;
				tot -= i - j;
				if(tot == u && u<=k){
					cout<<i<<endl;
					exit(0);
				}
			}
		}
	}
}