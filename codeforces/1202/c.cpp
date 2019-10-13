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
#define F first
#define S second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int t;
	cin >> t;
	while(t--){
		
		string s;
		cin >> s;
		n = s.size();
		int px[n+5] = {},py[n+5] = {};
		f1((int)s.size()){
			char c = s[i-1];
			if(c=='W'){
				px[i] = px[i-1] + 1;
				py[i] = py[i-1];
			}
			else if(c=='S'){
				px[i] = px[i-1] - 1;
				py[i] = py[i-1];
			}
			else if(c=='A'){
				px[i] = px[i-1];
				py[i] = py[i-1] + 1;
			}
			else{
				px[i] = px[i-1];
				py[i] = py[i-1] - 1;
			}
		}
		int mxx= 0,mxy = 0,mix = 0,miy = 0;
		f1(n){
			mxx = max(mxx,px[i]);
			mix = min(mix,px[i]);
			mxy = max(mxy,py[i]);
			miy = min(miy,py[i]);
		}
		int xcd = 0 ,ycd = 0;
		int xsz,ysz;
		xsz = mxx - mix + 1;
		ysz = mxy - miy + 1;
		int xtt = 0;
		int pre = 1e9;
		f(n+1){
			if(pre==1e9){
				if(px[i]==mxx||px[i]==mix){
					pre = px[i];
				}
			}
			else if(pre==mxx&&px[i]==mix){
				pre = mix;
				xtt++;
			}
			else if(pre==mix&&px[i]==mxx){
				pre = mxx;
				xtt++;
			}
		}
		if(xtt>1){
			xcd = 1;
		}
		int ytt = 0;
		pre = 1e9;
		f(n+1){
			if(pre==1e9){
				if(py[i]==mxy||py[i]==miy){
					pre = py[i];
				}
			}
			if(pre==mxy&&py[i]==miy){
				pre = miy;
				ytt++;
			}
			else if(pre==miy&&py[i]==mxy){
				pre = mxy;
				ytt++;
			}
		}
		if(ytt>1){
			ycd = 1;
		}
		if(xsz<=2)xcd = 1;
		if(ysz<=2)ycd = 1;
		//cout << xcd <<' '<<ycd << endl;
		ll ans = (ll)xsz * (ll)ysz;
		//cout <<xsz<<' '<<ysz<<endl;
		if(!xcd){
			ans = min(ans,(ll)(xsz-1) * (ll)ysz);
		}
		if(!ycd){
			ans = min(ans,(ll)(xsz) * (ll)(ysz-1));
		}
		cout << ans << '\n';
	}
}