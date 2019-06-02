#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a,b,c;
	while(cin >> a>>b>>c){
		ll ans = c*2+min(a,b)*2+(a!=b);
		cout << ans << endl;
	}
	
}