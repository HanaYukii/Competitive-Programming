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
const ll mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,q;
	while(cin >> n >> m >> k >> q){
		vector<int>pos[n+5];
		vector<int>qq;
		int last = 0;
		f(k){
			int add1,add2;
			cin >> add1 >> add2;
			pos[add1].pb(add2);
		}
		f1(n){
			if(!pos[i].size())continue;
			last = i;
			sort(pos[i].begin(),pos[i].end());
		}
		f(q){
			int add;
			cin >> add;
			qq.pb(add);
		}
		sort(qq.begin(),qq.end());
		ll dp[4] = {};
		int p[4] = {};
		if(last == 1){
			cout<<pos[1].back()-1<<endl;
			exit(0);
		}
		if(!pos[1].size()){
			p[0] = p[1] = p[2] = p[3] = qq[0];
			dp[0] = dp[1] = dp[2] = dp[3] = qq[0] - 1;
		}
		else{
			int ub,lb;
			if(lower_bound(qq.begin(),qq.end(),pos[1].back())==qq.end()){
				ub = lb = qq.back();
			}
			else if(lower_bound(qq.begin(),qq.end(),pos[1].back())==qq.begin()){
				ub = lb = qq[0];
			}
			else{
				int idx = lower_bound(qq.begin(),qq.end(),pos[1].back()) - qq.begin();
				ub = qq[idx];
				lb = qq[idx-1];
			}
			int r = pos[1].back();
			p[0] = p[1] = lb;
			p[2] = p[3] = ub;
			dp[0] = dp[1] = r - 1 + abs(r-lb);
			dp[2] = dp[3] = r - 1 + abs(r-ub);
			//cout<<"dp:"<<' '<<dp[0]<<' '<<dp[1]<<' '<<dp[2]<<' '<<dp[3]<<endl;
			//cout<<"pos:"<<' '<<p[0]<<' '<<p[1]<<' '<<p[2]<<' '<<p[3]<<endl;
		}
		fr(i,2,n+1){
			if(!pos[i].size())continue;
			int l = pos[i][0];
			int r = pos[i].back();
			int llb,lub,rlb,rub;
			if(lower_bound(qq.begin(),qq.end(),r)==qq.end()){
				rub = rlb = qq.back();
			}
			else if(lower_bound(qq.begin(),qq.end(),r)==qq.begin()){
				rub = rlb = qq[0];
			}
			else{
				int idx = lower_bound(qq.begin(),qq.end(),r) - qq.begin();
				rub = qq[idx];
				rlb = qq[idx-1];
			}
			if(lower_bound(qq.begin(),qq.end(),l)==qq.end()){
				lub = llb = qq.back();
			}
			else if(lower_bound(qq.begin(),qq.end(),l)==qq.begin()){
				lub = llb = qq[0];
			}
			else{
				int idx = lower_bound(qq.begin(),qq.end(),l) - qq.begin();
				lub = qq[idx];
				llb = qq[idx-1];
			}
			ll rMin = 1e18, lMin = 1e18;
			fr(j,0,4){
				rMin = min(rMin,dp[j]+abs(l-p[j])+abs(l-r));
				lMin = min(lMin,dp[j]+abs(r-p[j])+abs(l-r));
			}
			if(i == last){
				cout<<min(lMin,rMin) + last - 1 <<endl;
				exit(0);
			}
			p[0] = llb;
			dp[0] = lMin + abs(l-llb);
			p[1] = lub;
			dp[1] = lMin + abs(l-lub);
			p[2] = rlb;
			dp[2] = rMin + abs(r-rlb);
			p[3] = rub;
			dp[3] = rMin + abs(r-rub);
			//cout <<i<<":"<<endl;
			//cout<<"dp:"<<' '<<dp[0]<<' '<<dp[1]<<' '<<dp[2]<<' '<<dp[3]<<endl;
			//cout<<"pos:"<<' '<<p[0]<<' '<<p[1]<<' '<<p[2]<<' '<<p[3]<<endl;
		}
	}
}