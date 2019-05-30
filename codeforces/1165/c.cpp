#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=1e9+7;

int main(){
	int n;
	while(cin >> n){
		string s;
		cin >> s;
		int now=0;
		char last;
		vector<char>ans;
		for(int i=0;i<n;i++){
			if(now==0){
				last=s[i];
				now=1;
			}
			else{
				if(s[i]!=last){
					now=0;
					ans.pb(last);
					ans.pb(s[i]);
				}
			}
		}
		cout<<n-ans.size()<<endl;
		for(auto i:ans){
			cout<<i;
		}
		cout<<endl;
	}
}