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
	vector<int>v;
	f(n){
		int add;
		cin >> add;
		v.pb(add);
	}
	sort(v.begin(),v.end());
	int cnt=0,now=1;
	for(auto i:v){
		if(i>=now){
			cnt++,now++;
		}
	}
	cout<<now-1<<endl;
}
}