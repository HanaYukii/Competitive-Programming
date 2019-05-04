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

	ll a,b;
	cin >>a>>b;
	ll now=1;
	while(a--){
		now*=2;
		if(now>b){
			cout<<b<<endl;
			exit(0);
		}
	}
	cout<<b%now<<endl;
}