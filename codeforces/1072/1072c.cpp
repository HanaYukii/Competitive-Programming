#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
	long long n,m;
	while(cin>>n>>m){
		long long ans=0;
		cout<<sizeof(ans)<<endl;
		for(long long i=1<<18;i;i>>=1){
			if((ans+i)*(ans+i+1)/2<=n+m){
				ans+=i;
			}
		}
		vector<long long>ans1,ans2;
		int u[ans+5]={};
		for(long long i=ans;n>=i&&i;i--){
			n-=i;
			ans1.pb(i);
			u[i]=1;
		}
		if(n&&!u[n]){
			ans1.pb(n);
			u[n]=1;
		}
		for(int i=1;i<=ans;i++){
			if(!u[i]){
				ans2.pb(i);
			}
		}
		cout<<ans1.size()<<endl;
		for(long long i:ans1){
			cout<<i<<' ';
		}
		cout<<endl;
		cout<<ans2.size()<<endl;
		for(long long i:ans2){
			cout<<i<<' ';
		}
		cout<<endl;
	}	
}