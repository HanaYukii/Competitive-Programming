#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;

int main(){
	long long n,k;
	while(cin>>n>>k){
		ll cont[100005];
		ll sum=0;
		f(n){
			cin>>cont[i];
			sum+=cont[i];
		}
		int f=0;
		if(sum%k){
			f=1;
		}
		sum/=k;
		ll now=0;
		vector<int>ans;
		int cnt=0;
		f(n){
			if(f){
				break;
			}
			now+=cont[i];
			cnt++;
			if(now>sum){
				f=1;
				break;
			}
			else if(now==sum){
				ans.pb(cnt);
				cnt=0;
				now=0;
			}
		}
		if(now){
			f=1;
		}
		if(f){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
			for(int i:ans){
				cout<<i<<' ';
			}
		}
	}	
}