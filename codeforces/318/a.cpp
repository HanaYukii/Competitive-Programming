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
const int mod = 1e9+7;
const long long INF = 1LL<<60;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	while(cin >> n >> m){
		if(n&1){
			if(m<=n/2+1){
				cout<<m*2-1<<endl;
			}
			else{
				cout<<(m-n/2-1)*2<<endl;
			}
		}
		else{
			if(m<=n/2){
				cout<<2*m-1<<endl;
			}
			else{
				cout<<(m-n/2)*2<<endl;
			}
		}
	}
}