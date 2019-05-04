#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define bg begin()
#define ed end()
using namespace std;

int main()
{
	int t;
	cin >> t;
    for (int c = 1 ;c<=t;c++)
    {
        int n;
        cin >> n ;
        ll mxx=0,mix=1e18,mxy=0,miy=1e18;
        f(n){
        	ll x,y;
        	cin >> x >> y;
        	mxx=max(mxx,x);
        	mxy=max(mxy,y);
        	miy=min(miy,y);
        	mix=min(mix,x);
        }
        ll ans=(max(mxx-mix,mxy-miy)+1)/2;
        	printf("Case #%d: %lld\n",c,ans);
        
    }
    return 0;
}
