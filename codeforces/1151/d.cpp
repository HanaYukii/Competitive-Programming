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
#define pii pair<ll,ll>
bool cmp(pii a,pii b){
	return a.first-a.second>b.first-b.second;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	while(cin >>n ){
		vector<pii>v;
		f(n){
			ll add1,add2;
			cin >> add1 >> add2;
			v.pb({add1,add2});
		}
		sort(v.bg,v.ed,cmp);
		ll sum=0;
		for(int i=0;i<n;i++){
			sum+=v[i].first*i+v[i].second*(n-i-1);
		}
		cout<<sum<<endl;
	}

}