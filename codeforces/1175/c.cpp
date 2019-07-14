#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const ll inf=1e10;
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n,k;
    	cin >> n >> k;
    	vector<ll>v;
    	f(n){
    		ll add;
    		cin >> add;
    		v.pb(add);
    	}
    	ll mi=0;
    	for(ll i=1LL<<32;i>1;i>>=1){
    		int f = 0;
    		ll now = (1LL<<32)-i-mi;
    		for(int j=0;j<n;j++){
    			int cnt = upper_bound(v.begin(),v.end(),v[j]+now)-v.begin()-j;
    			if(cnt > k){
    				f=1;
    				break;
    			}
    		}
    		if(f){
    			mi += i;
    		}
    	}
    	mi=(1LL<<32)-mi;
    	for(int j=0;j<n;j++){
    		int cnt = upper_bound(v.begin(),v.end(),v[j]+mi)-v.begin()-j;
    		if(cnt > k){
				cout<<v[j]+mi/2<<'\n';
				break;
    		}		
    	}
    }
 
}