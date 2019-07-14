#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
 
int main(){
	string a,b;
	while(cin >> a >> b){
		int n = a.size();
		int m = b.size();
		int pre[n+5] = {};
		f1(n){
			if(a[i-1]=='1'){
				pre[i]=pre[i-1]+1;
			}
			else{
				pre[i]=pre[i-1];
			}
		}
		int cnt = 0,ans = 0;
		f(m){
			cnt += (b[i]=='1');
		}
		for(int i=m;i<=n;i++){
			int now = pre[i]-pre[i-m];
			now = abs(now-cnt);
			if((now&1)==0)ans++;
		}
		cout << ans << endl;
	}
}