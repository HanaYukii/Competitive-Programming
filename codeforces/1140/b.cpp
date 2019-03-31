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
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		int pre = 0 , suf = 0;
		for(int i = 0 ;i < (int)s.size() ;i++){
			if(s[i] == '<'){
				pre++;
			}
			else{
				break;
			}
		}
		for( int i = n-1 ;i >= 0 ;i--){
			if(s[i] == '>'){
				suf++;
			}
			else{
				break;
			}
		}
		cout << min(pre,suf) << '\n';
	}
}