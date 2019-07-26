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
bool isp(int x){
	for(int i=2;i<=sqrt(x);i++){
		if(x%i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		vector<pair<int,int> >ans;
		f1(n-1){
			ans.pb({i,i+1});
		}
		ans.pb({n,1});
		for(int i=1;i<=n/2&&!isp(ans.size());i++){
			ans.pb({i,(i+n/2)});
		}
		cout << ans.size()<<endl;
		for(auto i:ans){
			cout << i.F <<' '<<i.S <<'\n';
		}
		cout << endl;
	}
}