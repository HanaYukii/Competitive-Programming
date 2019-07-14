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
#define bg begin()
#define ed end()
#define pii pair<int,int>
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<int,int>mp;
	multiset<int>st;
	f(n<<1){
		int add;
		cin >> add;
		st.insert(add);
	}
	mp[2]=1;
	int cnt = 2;
	for(int i=3;i<=2750131;i+=2){
		int f = 0;
		for(int j=3;j<=(int)sqrt(i);j+=2){
			if(i%j==0){
				f=1;
				break;
			}
		}
		if(!f){
			mp[i] = cnt++;
		}
	}
	vector<int>ans;
	while(ans.size()<n){
		int now=*(--st.end());
		st.erase(st.lower_bound(now));
		if(mp.find(now)==mp.end()){
			ans.pb(now);
			for(int i=2;i<=sqrt(now);i++){
				if(now%i==0){
					st.erase(st.lower_bound(now/i));
					break;
				}
			}
		}
		else{
			ans.pb(mp[now]);
			st.erase(st.lower_bound(mp[now]));
		}
	}
	for(auto i:ans){
		cout<<i<<' ';
	}
	cout <<endl;
}