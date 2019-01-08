#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define maxn 200005
#define endl '\n'
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	ll n;
	while(cin>>n){
		ll a,b;
		cin>>a>>b;
		if(max(n-a,n-b)<max(a-1,b-1)){
			cout<<"Black"<<endl;
		}
		else{
			cout<<"White"<<endl;
		}
	}
}