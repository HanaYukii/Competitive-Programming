#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
const ll mod=998244353;
int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		string s;
		cin >> s;
		int n=s.size();
		int need=(n-1)/2+((n-1)&1);
		int cb = 0;
		for(auto i:s){
			if(i=='B')cb++;
		}
		if(cb==n-1||cb<need){
			printf("Case #%d: N\n",c);
		}
		else{
			printf("Case #%d: Y\n",c);
		}
	}
}