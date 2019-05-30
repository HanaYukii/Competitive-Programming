#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=998244353;

int main(){
	ll n,k;
	while(cin >> n){
		int cnt[26]={};
		f(n){
			string s;
			cin >> s;
			cnt[s[0]-'a']++;
		}
		int ans=0;
		f(26){
			int x=cnt[i]/2;
			int y=cnt[i]-x;
			ans+=x*(x-1)/2+y*(y-1)/2;
		}
		cout << ans << endl;
	}
}