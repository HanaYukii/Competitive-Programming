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
	int t;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;c++){
		int n;
		cin>>n;
		vector<int>v1,v2,ans;
		f(n){
			int add;
			cin>>add;
			if(i&1){
				v2.pb(add);
			}
			else{
				v1.pb(add);
			}
			ans.pb(add);
		}
		sort(ans.begin(),ans.end());
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		int f=0;
		f(n){
			if(f)continue;
			if(i&1){
				if(ans[i]!=v2[i/2]){
					f=i+1;
				}
			}
			else{
				if(ans[i]!=v1[i/2]){
					f=i+1;
				}
			}
		}
		if(f){
			cout<<"Case #"<<c<<": "<<f-1<<endl;
		}
		else{
			cout<<"Case #"<<c<<": OK"<<endl;
		}
	}
}