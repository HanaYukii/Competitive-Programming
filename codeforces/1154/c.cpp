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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll a,b,c,d;
	while(cin >> a>>b>>c>>d){
		vector<int>v;
		v.pb(a);v.pb(b);v.pb(c);v.pb(d);
		sort(v.bg,v.ed);
		cout<<v[3]-v[2]<<' '<<v[3]-v[1]<<' '<<v[1]+v[2]-v[3]<<endl;
	}

}