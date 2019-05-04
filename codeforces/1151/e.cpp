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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >>n){
		ll cont[n+5] = {};
		f(n)cin >> cont[i];
		ll ans = 0;
		ans=cont[0]*(n+1-cont[0]);
		f1(n-1){
			ans+=cont[i]*(n+1-cont[i]);
			ans -=min(cont[i],cont[i-1])*(n+1-max(cont[i],cont[i-1]));
		}
		cout << ans << endl;
	}

}