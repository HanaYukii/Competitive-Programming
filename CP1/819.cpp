#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int maxn=1005;


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	while(getline(cin,str)){
		//vector<string>v;
		stringstream ss(str);
		string add;
		int mx=0;
		vector<int>ans;
		while(ss>>add){
			reverse(add.begin(),add.end());
			while(ans.size()<add.size()){
				ans.pb(0);
			}
			for(int j=0;j<(int)add.size();j++){
				ans[j]+=add[j]-'0';
			}
			mx=max(mx,(int)add.size());
		}
		for(int i=0;i<mx-1;i++){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		int f=0;
		for(int i=mx-1;i>=0;i--){
			if(ans[i])f=1;
			if(f)
			cout<<ans[i];
		}
		if(!f)cout<<0;
		cout<<'\n';
	}

}