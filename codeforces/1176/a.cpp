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
const ll mod = 1e9+7;
int main(){
	int t;
	cin >> t;
	while(t--){
		ll num;
		cin >> num;
		ll ans = 0;
		while(num%5==0){
			num /=5;
			num *=4;
			ans ++;
		}
		while(num%3==0){
			num /= 3;
			num*= 2;
			ans++;
		}
		while(num%2==0){
			num/=2;
			ans++;
		}
		if(num!=1){
			cout<<-1<<'\n';
		}
		else{
			cout<<ans<<endl;
		}
	}
}