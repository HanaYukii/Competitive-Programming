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
       	int n;
       	cin >> n ;
        vector<pair<ll,ll> >v;
        f(n){
        	ll add1,add2;
        	cin >> add1 >> add2;
        	v.pb({add1,add2});
        }
        sort(v.begin(),v.end());
        set<pair<ll,ll> >st;
        int ans=1;
        for(int i=0;i<n;i++)
        	for(int j=i+1;j<n;j++){
        	ll x=v[i].second-v[j].second;//__gcd(v[i].second-v[i-1].second,v[i].first-v[i-1].first);
        	ll y=v[i].first-v[j].first;//__gcd(v[i].second-v[i-1].second,v[i].first-v[i-1].first);
        	if(!x||!y||x*y>0)continue;
        	ll g=__gcd(x,y);
        	x/=g;
        	y/=g;
        	//cout<<x<<' '<<y<<endl;
        	//cout << x <<' '<< y<<endl;
        	if(st.find({x,y})==st.end())ans++;
        		st.insert({x,y});
        	
        }
        printf("Case #%d: %d\n",c,ans);
        
    }
    return 0;
}
