#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	while(cin >> n >> k){
		ll a,b;
		cin >> a >> b;
		ll now1 = 1+a,now2 = k+1-a;
		ll fir1 = 1+b,fir2 = k+1-b;
		ll mx=1,mn=n*k;
		f(n*2){
			//cout<<fir1 <<' '<<fir2<<endl;
			if(fir1 > now1){
				mn=min(mn,(n*k)/__gcd(n*k,fir1-now1));
				mx=max(mx,(n*k)/__gcd(n*k,fir1-now1));
			}
			if(fir2 > now1){
				mn=min(mn,(n*k)/__gcd(n*k,fir2-now1));
				mx=max(mx,(n*k)/__gcd(n*k,fir2-now1));
			}
			if(fir1 > now2){
				mn=min(mn,(n*k)/__gcd(n*k,fir1-now2));
				mx=max(mx,(n*k)/__gcd(n*k,fir1-now2));
			}
			if(fir2 > now2){
				mn=min(mn,(n*k)/__gcd(n*k,fir2-now2));
				mx=max(mx,(n*k)/__gcd(n*k,fir2-now2));
			}
			fir1+=k;
			fir2+=k;
		}
		cout << mn << ' '<< mx <<endl;	
	}
}