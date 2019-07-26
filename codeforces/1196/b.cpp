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
#define F first
#define S second
const ll mod = 998244353;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		ll sum = 0;
		vector<int>ans;
		int cont[n+5] = {};
		f(n){
			cin >> cont[i];
			sum += cont[i];
		}
		if((sum&1)^(k&1)){
			cout<<"NO"<<'\n';
			continue;
		}
		else{
			ll cur = 0;
			f(n){
				cur += cont[i];
				if(cur&1){
					cur = 0;
					ans.pb(i+1);
				}
			}
			if(ans.size()>=k){
				cout<<"YES"<<'\n';
				f(k-1){
					cout<<ans[i]<<' ';
				}
				cout<<n<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
}