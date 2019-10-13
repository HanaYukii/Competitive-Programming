#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c;
	while(cin >> a >> b >> c){
		multiset<int>st1,st2,st3;
		ll ans = 0;
		int n;
		cin >> n ;
		f(n){
			int add;
			string s;
			cin >> add >> s;
			if(s=="USB"){
				st1.insert(add);
				st3.insert(add);
			}
			else{
				st2.insert(add);
				st3.insert(add);
			}
		}
		while(a--&&st1.size()){
				int add;
				add = *st1.begin();
				st1.erase(st1.lower_bound(add));
				st3.erase(st3.lower_bound(add));
				ans += add;
			}
			while(b--&&st2.size()){
				int add;
				add = *st2.begin();
				st2.erase(st2.lower_bound(add));
				st3.erase(st3.lower_bound(add));
				ans += add;
			}
			while(c--&&st3.size()){
				int add;
				add = *st3.begin();
				st3.erase(st3.lower_bound(add));
				ans += add;
			}
			cout<<n-st3.size()<<' '<<ans<<endl;
	}
}