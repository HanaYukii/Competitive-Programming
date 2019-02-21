#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back

int main(){
	int n,q;
	int t;
	cin>>t;
    while(t--){
    	ll a,b,c;
    	cin>>a>>b>>c;
    	if(c>=b*2){
    		cout<<b*a<<endl;
    	}
    	else{
    		cout<<c*(a/2)+(a&1)*b<<endl;
    	}
    }
}