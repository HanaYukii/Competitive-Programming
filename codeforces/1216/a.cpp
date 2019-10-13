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
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i=0;i<n;i+=2){
		if(s[i]==s[i+1]){
			ans++;
			if(s[i]=='a'){
				s[i+1]='b';
			}
			else{
				s[i]='a';
			}
		}
	}
	cout << ans << endl;
	cout << s << endl;
}