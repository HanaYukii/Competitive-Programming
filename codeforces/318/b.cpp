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
const int mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(cin >> s){
		int cur = 0;
		ll ans = 0;
		int n = s.size();
		for(int i=4;i<n;i++){
			if(s[i-4]=='h'&&s[i-3]=='e'&&s[i-2]=='a'&&s[i-1]=='v'&&s[i]=='y'){
				cur++;
			}
			if(s[i-4]=='m'&&s[i-3]=='e'&&s[i-2]=='t'&&s[i-1]=='a'&&s[i]=='l'){
				ans += cur;
			}
		}
		cout << ans << endl;
	}
}