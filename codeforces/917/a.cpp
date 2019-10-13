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
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(cin >> s){
		int n = s.size();
		int ans = 0;
		for(int i=0;i<n;i++){
			int cur = 0;
			int left = 0;
			for(int j = i ; j<n ;j ++){
				if(s[j]=='('){
					cur++;
				}
				else if(s[j]==')'){
					cur--;
				}
				else{
					cur--;
					left++;
				}
				if(!cur){
					ans++;
				}
				if(cur < 0){
					if(!left){
						break;
					}
					else{
						cur += 2;
						left--;
					}
				}
			}
		}
		cout << ans << endl;
	}
}