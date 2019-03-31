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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin >> n >> k){
		multiset< pair<ll,ll> >st;
		for(int i = 0; i < n ;i++){
			ll add1,add2;
			cin >> add1 >> add2;
			st.insert({add2 ,add1});
		}
		multiset<ll>cur;
		ll sum = 0;
		ll Min=1e18;
		ll mx=0;
		while(!st.empty()){
			pair<ll,ll>now =*(--st.end());
			Min = min(Min,now.first);
			if(cur.size() < k){
				cur.insert(now.second);
				sum += now.second;
			}
			else{
				if(now.second > *cur.begin()){
					sum -= *(cur.begin());
					cur.erase(cur.begin());
					sum += now.second;
					cur.insert(now.second);
				}
			}
			mx = max(mx,sum*Min);
			st.erase(--st.end());
		}
		cout << mx << endl;
	}
}