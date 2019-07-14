#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 250005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	while(cin >> n >> k){
		string s;
		int mxo = 0;
		int mio = 1e6;
		int mxx = 0;
		int mix = 1e6;
		cin >> s;
		s = " "+s;
		vector<int>z,o;
		f1(n){
			if(s[i]=='0'){
				mxo = max(mxo,i);
				mio = min(mio,i);
				z.pb(i);
			}
			else{
				mxx = max(mxx,i);
				mix = min(mix,i);
				o.pb(i);
			}
		}
		z.pb(1e6);
		o.pb(1e6);
		if(max(mxx-mix+1,mxo-mio+1)>n){
			cout<<"quaility"<<endl;
			exit(0);
		}
		if(min(mxx-mix+1,mxo-mio+1)<=k){
			cout<<"tokitsukaze"<<endl;
		}
		else{
			int f = 0;
			for(int i=1;i<=n-k+1;i++){
				int bg,ed;
				if(z[0]<i){
					bg = z[0];
				}
				else{
					bg = *lower_bound(z.begin(),z.end(),i+k);
				}
				if(bg <=n){
					ed = z[z.size()-2];
					if(ed <= i+k-1){
						ed = *(--lower_bound(z.begin(),z.end(),i));
					}
					if(ed - bg + 1 >= k){
						f = 1;
						break;
					}
				}
				if(o[0]<i){
					bg = o[0];
				}
				else{
					bg = *lower_bound(o.begin(),o.end(),i+k);
				}
				if(bg <= n){
					ed = o[o.size()-2];
					if(ed <= i+k-1){
						ed = *(--lower_bound(o.begin(),o.end(),i));
					}
					if(ed - bg +1 >= k){
						f = 1;
					}
				}
			}
			if(f){
				cout<<"once again"<<endl;
			}
			else{
				cout<<"quailty"<<endl;
			}
		}
	}
}