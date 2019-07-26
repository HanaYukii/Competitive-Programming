#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
const ll mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int z=1;z<=t;z++){
		string s1,s2,s3;
		cin >> s1 >> s2 >> s3;
		map<char,int>mp;
		for(auto i:s1){
			mp[i]--;
		}
		for(auto i:s2){
			mp[i]++;
		}
		for(auto i:s3){
			mp[i]--;
		}
		int p1 = 0 ,p2 = 0;
		int f = 0;
		for(auto i:mp){
			if(i.second>0){
				f = 1;
			}
		}
		while(p1<s1.size()&&p2<s2.size()){
			if(s1[p1]==s2[p2]){
				p1++,p2++;
			}
			else{
				p2++;
			}
		}
		if(p1 != s1.size()){
			f = 1;
		}
		if(f){
			cout<<"NO"<<'\n';
		}
		else{
			cout<<"YES"<<'\n';
		}
	}
 
}