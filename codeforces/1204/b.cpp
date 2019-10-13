#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int main(){
	ll n,l,r;
    while(cin>>n>>l>>r){
    	ll ans1 = 0,ans2 = 0;
    	int rr = r-1;
    	int rn = n;
    	ll now = 1;
    	while(rn--){
    		ans2 += now;
    		if(rr){
    			now<<=1;
    			rr--;
    		}
    	}
    	now=1<<(l-1);
    	rn = n;
    	while(rn--){
    		ans1 += now;
    		if(now>1){
    			now>>=1;
    		}
    	}
    	cout << ans1 <<' '<<ans2<<endl;
    }
}