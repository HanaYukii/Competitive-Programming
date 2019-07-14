#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
 
int main(){
	int n,m;
	while(cin >> n >> m){
		set<int>st;
		f1((1<<n)-1){
			st.insert(i);
		}
		st.erase(m);
		f1(((1<<n)-1)){
			if(st.find(i)!=st.end()){
				st.erase(m^i);
			}
		}
 
		vector<int>ans;
		int now = 0;
		for(auto i:st){
			ans.pb(now^i);
			now = i;
		}
		cout << ans.size() << endl;
		for(auto i:ans){
			cout << i << ' ';
		}
		cout << endl;
	}
}