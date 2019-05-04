#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define bg begin()
#define ed end()
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll x,y,p,q;
		cin >> x >> y >> p >> q;
		if(p==q){
			if(x==y){
				cout<<0<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
		else if(p==0){
			if(x==0){
				cout<<0<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
		else{
			ll can = 0;
			ll org= 1<<30;
			for(ll i=1<<29;i;i>>=1){
				ll now=can+i;
				ll t=org-now;
				if((q-p)*t>=y-x&&q*t>=y&&p*t>=x){
					can += i;
				}
			}
			cout<<q*(org-can)-y<<endl;
		}
		
	}
}