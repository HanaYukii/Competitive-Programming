#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 250005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	while(cin >> n){
		if(n%4==0){
			cout<<1<<' '<<'A'<<endl;
		}
		else if(n%4==1){
			cout<<0<<' '<<'A'<<endl;
		}
		else if(n%4==2){
			cout<<1<<' '<<'B'<<endl;
		}
		else{
			cout<<2<<' '<<'A'<<endl;
		}
	}
}