#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
long long d[maxn];
int chk[maxn];
int main(){
	ll m,a,b;
	cin >> m >> a >> b;
	for(int i=0;i<a;i++){
		d[i] = m+1;
	}
	d[0] = 0;
	priority_queue<pair<ll , ll >,vector<pair<ll,ll> >,greater< pair<ll,ll> > >q;
	q.emplace(0,0);
	while(!q.empty()){
		auto cur=q.top();
		q.pop();
		ll u = cur.second;
		if(chk[u])continue;
		chk[u]=1;
		ll v=((u-b)%a+a)%a;
		ll w=max(d[u],(v+b-u)/a*a+u);
		if(d[v]>w){
			d[v]=w;
			q.emplace(d[v],v);
		}
	}
	//f(a){
		//cout<<d[i]<<' ';
	//}
	//cout<<endl;
	long long ans = 0;
    for (int i = 0; i < a && i <= m; i++) {
        if (d[i] <= m) {
            long long j = (m - i) / a;
            long long k = (d[i] - i) / a;
            ans += (m + 1 - d[i]) * (k + 1) + (j - k) * (m + 1 - i) - (j + 1 + k) * (j - k) / 2 * a;
        }
    }
    cout << ans << endl;
    return 0;
}