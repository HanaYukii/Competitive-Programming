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
const int mod = 1e9+7;
bool isp(int x){
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0)return 0;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		vector<int>ans;
		for(int i=2;i<=n;i++){
			if(!isp(i))continue;
			int now = i;
			while(now<=n){
				ans.pb(now);
				now *= i;
			}
		}
		cout<<ans.size()<<endl;
		for(auto i:ans){
			cout<<i<<' ';
		}
		cout << endl;
	}		
}