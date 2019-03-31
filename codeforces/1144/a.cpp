#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int mx=0,mi=25;
		set<int>st;
		for(auto i:s){
			mx=max(mx,i-'a');
			mi=min(mi,i-'a');
			st.insert(i-'a');
		}
		if(st.size()==s.size()&&mx-mi+1==s.size()){
			cout<<"Yes"<<'\n';
		}
		else{
			cout<<"No"<<'\n';
		}
	}

}