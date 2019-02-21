#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const int mod=1e9+7;
int main(){
	int n,m;
	while(cin>>n>>m){
		ll cnt=0;
		for(int i=m-1;i>0;i--){
			cnt+=i;
		}
		cnt<<=1;
		if(cnt<n){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			cnt=0;
			int gp=1;
			while(1){
				for(int i=1;i<=m-gp;i++){
					cout<<i<<' '<<i+gp<<endl;
					cnt++;
					if(cnt==n){
						exit(0);
					}
				}
				for(int i=m-gp;i>=1;i--){
					cout<<i+gp<<' '<<i<<endl;
					cnt++;
					if(cnt==n){
						exit(0);
					}
				}
				gp++;
			}
		}
	}
}