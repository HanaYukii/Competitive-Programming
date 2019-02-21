#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	int n,m;
	while(cin>>n>>m){
		if(n<=m){
			cout<<n-1<<endl;
		}
		else{
			int ans=m;
			for(int i=2;i<=n-m;i++){
				ans+=i;
			}
			cout<<ans<<endl;
		}
		//cout<<ans<<endl;
	}
}