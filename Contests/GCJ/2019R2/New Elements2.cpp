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

int main()
{
	int t;
	cin >> t;
    for (int c = 1 ;c <= t;c++)
    {
       	vector<pair<ll,ll> >v;
       	int n;
       	cin >> n;
        f(n){
        	ll add1,add2;
        	cin >> add1 >> add2;
        	v.pb({add1,add2});
        }
        ll ansx=0,ansy=0;
       	for(ll i=1;i<=500;i++){
       		for(ll j=1;j<=500;j++){
       			int f=0;
       			vector<ll>tt;
       			ll last = 0;
       			for(auto k:v){
       				ll now=k.first*i+k.second*j;
       				if(now<=last){
       					f=1;
       					break;
       				}
       				last=now;
       			}
       			if(!f){
       				ansx=i;
       				ansy=j;
       				goto endd;
       			}
       		}
       	}

        endd:;
        if(ansx){
        	printf("Case #%d: %lld %lld\n",c,ansx,ansy);
        }
        else{
        	printf("Case #%d: IMPOSSIBLE\n",c);
        }
    }
    return 0;
}
