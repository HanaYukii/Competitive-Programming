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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<ll>v;
		f(n){
			ll add;
			cin >> add;
			v.pb(add);
		}
		sort(v.begin(), v.end());
		ll ans;
		set<ll>st;
		for(auto i:v){
			st.insert(i);
		}
		if(v.size()==1){
			ans=v[0]*v[0];
		}
		else{
			ans=v[0]*v[v.size()-1];
		}
		for(int i=2;i<=(ll)sqrt(ans);i++){
			if((ans%i==0)&&i!=ans){
				if(st.find(i)==st.end()||st.find(ans/i)==st.end()){
					cout<<-1<<endl;
					goto endd;
				}
				else{
					st.erase(i);
					st.erase(ans/i);
				}
			}
		}
		//cout<<st.size()<<endl;
		if(st.size()==0){
			cout<<ans<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		endd:;
	}
}