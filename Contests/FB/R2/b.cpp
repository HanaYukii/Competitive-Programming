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
int d[4005];
int fi(int x){
	return d[x] == x ? d[x] : d[x] = fi(d[x]);
}
int main(){
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		int n , m;
		cin >> n >> m;
		f1(n){
			d[i] = i;
		}
		f(m){
			int l,r;
			cin >> l >> r;
			int dif = (r-l+1)/2;
			for(int j=0;j<dif;j++){
				int x = fi(l+j);
				int y = fi(r-j);
				d[x] = y;
			}
		}
		map<int,int>mp;
		f1(n){
			d[i] = fi(d[i]);
			mp[d[i]]++;
		}
		int dp[n+5] = {1};
		int from[n+5] = {};
		for(auto i:mp){
			for(int j=n;j>=i.second;j--){
				if(!dp[j] && dp[j-i.second]){
					dp[j] = 1;
					from[j] = i.second;
				}
			}
		}
		int mid = n/2;
		int goal = 0;
		for(int i = mid;i>=0;i--){
			if(dp[i]){
				goal = i;
				break;
			}
		}		
		multiset<int>st;
		int now = goal;
		while(now!=0){
			st.insert(from[now]);
			now -= from[now];
		}
		unordered_set<int>zero;
		for(auto i:mp){
			if(st.find(i.second)!=st.end()){
				zero.insert(i.first);
				st.erase(st.lower_bound(i.second));
			}
		}
		string ans="";
		f1(n){
			int xx = d[i];
			if(zero.find(xx)!=zero.end()){
				ans+="0";
			}
			else{
				ans+="1";
			}
		}
		printf("Case #%d: ",c);
		cout<<ans<<endl;
	}

}