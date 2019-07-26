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
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	while(cin >> n){
		ll sum = 0;
		vector<int>idx;
		ll cur = 0;
		ll cont[n+5] = {};
		f1(n){
			cin >> cont[i];
			sum += cont[i];
		}
		idx.pb(1);
		cur = cont[1];
		fr(i,2,n+1){
			if(cont[i]<=cont[1]/2){
				cur += cont[i];
				idx.pb(i);
			}
		}
		if(cur*2 > sum){
			cout<<idx.size()<<endl;
			for(auto i:idx){
				cout<<i<<' ';
			}
			cout << endl;
		}
		else{
			cout<<"0"<<endl;
		}
	}
}