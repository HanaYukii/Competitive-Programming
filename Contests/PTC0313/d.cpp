#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int dp(vector<int>v){
	if(v.size()==0){
		return 0;
	}
	int mx=0;
	for(int i=0;i<v.size();i++){
		vector<int>tmp;
		set<int>ct;
		ct.insert(v[i]);
		ct.insert(v[i]*2+1);
		ct.insert(v[i]*2+2);
		ct.insert(v[i]*4+3);
		ct.insert(v[i]*4+4);
		ct.insert(v[i]*4+5);
		ct.insert(v[i]*4+6);
		for(int j=0;j<v.size();j++){
			if(ct.find(v[j])==ct.end()){
				tmp.pb(v[j]);
			}
		}
		mx=max(dp(tmp)^1,mx);
	}
	return mx;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int win=1;
		f(n){
			int k;
			cin>>k;
			vector<int>v;
			int tr;
			cin>>tr;
			f(k-1){
				int add;
				cin>>add;
				v.pb(add);
			}
			int r=dp(v);
			if(r==1){
				win^=1;
			}
		}
		if(win==1){
			cout<<"Ella wins"<<endl;
		}
		else{
			cout<<"Emma wins"<<endl;
		}
	}
}