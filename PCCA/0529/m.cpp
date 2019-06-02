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
	ll a,b;
	while(cin >> a >> b){
		vector<int>v;
		//int now = 1;
		for(int i=b;i<=a*b;i+=b){
			for(int j=i;j>i-b;j--){
				v.pb(j);
			}
		}
		cout<<v.size()<<endl;
		for(auto i:v){
			cout<<i<<' ';
		}
		cout << endl;
	}
}