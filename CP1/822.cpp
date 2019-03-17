#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
bitset<10000005>b;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll n,l,r;
		cin>>n>>l>>r;
		int sz=min((int)(r-l+1),10000000);
		
		f(sz)b[i]=0;
		f(n){
			ll add;
			cin>>add;
			if(add<=r&&add>=l&&add-l<sz){
				b[add-l]=1;
			}
		}
		ll now=l+sz;
		for(int i=0;i<sz;i++){
			if(!b[i]){
				cout<<l+i<<'\n';
				goto endd;
			}
		}
		if(now!=r+1){
			cout<<now<<'\n';
		}
		else{
			cout<<"^v^"<<'\n';
		}
		endd:;
	}
}