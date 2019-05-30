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

int main(){
	int n;
	string s;
	while(cin >> s){
		ll ans = 0;
		n = s.size();
		for(int i=0;i<n;i++){
			vector<int>z,o;
			int f = 0;
			for(int j=i;j<n;j++){
				if(s[j]=='0')z.pb(j);
				else o.pb(j);
				for(int x=0;x<z.size();x++){
					for(int y=x+1;y<z.size();y++){
						for(int zz=y+1;zz<z.size();zz++){
							if(z[x]+z[zz]==2*z[y]){
								f=1;
							}
						}
					}
				}
				for(int x=0;x<o.size();x++){
					for(int y=x+1;y<o.size();y++){
						for(int zz=y+1;zz<o.size();zz++){
							if(o[x]+o[zz]==2*o[y]){
								f=1;
							}
						}
					}
				}
				if(f){
					ans += n-j;break;
					//cout<<i<<' '<<j<<endl;
				}
			}
		}
		cout << ans << endl;
	}
}