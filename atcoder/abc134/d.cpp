#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=1e9+7;
 
int main(){
	int n;
	while(cin >> n){
		int cont[n+5] = {};
		int u[n+5] = {};
		f1(n)cin >> cont[i];
		for(int i=n;i>0;i--){
			int cnt = 0;
			for(int j = 2 * i ; j <= n ; j += i){
				if(u[j])cnt ^= 1;
			}
			if(cnt^cont[i]){
				u[i] = 1;
			}
		}
		vector<int>v;
		f1(n){
			if(u[i])v.pb(i);
		}
		cout << v.size() << endl;
		for(auto i:v){
			cout << i << ' ';
		}
		cout << endl;
	}
 
}