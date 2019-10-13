#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		multiset<int>st;
		f(n){
			int add;
			cin >> add;
			st.insert(add);
		}
		int f = 0;
		if(st.find(2048)!=st.end()){
			f = 1;
		}
		else{
			while(st.size()&&!f){
				int low = *st.begin();
				if(low > 2048)break;
				st.erase(st.lower_bound(low));
				if(st.find(low)!=st.end()){
					st.erase(st.lower_bound(low));
					st.insert(low<<1);
					if(low==1024)f=1;
				}
			}
		}
		if(f){
			cout<<"YES"<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}
}