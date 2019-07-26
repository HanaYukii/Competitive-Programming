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
	string s;
	while(cin >> s){
		int n = s.size();
		s = " "+s;
		ll pre[n+5] = {};
		ll suf[n+5] = {};
		fr(i,2,n+1){
			if(s[i] == s[i-1] && s[i-1]=='v'){
				pre[i] = pre[i-1] +1;
			}
			else{
				pre[i] = pre[i-1];
			}
		}
		for(int i = n-1 ; i >= 1 ; i--){
			if(s[i] == s[i+1] && s[i] =='v'){
				suf[i] = suf[i+1] +1;
			}
			else{
				suf[i] = suf[i+1];
			}
		}
		ll sum = 0;
		fr(i,3,n-1){
			if(s[i]=='o'){
				sum += pre[i-1] * suf[i+1];
			}
		}
		cout << sum << endl;
	}
}