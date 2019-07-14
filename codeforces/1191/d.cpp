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
	ll n;
	while(cin >> n){
		vector<ll>v;
		f(n){
			ll add;
			cin >> add;
			v.pb(add);
		}
		ll cnt = 0;
		ll pre = 0;
		sort(v.begin(),v.end());
		int cntcb=0;;
		f1(n){
			if(v[i]==v[i-1]){
				if(i>=2){
					if(v[i-2]+1==v[i-1])cntcb =2;
					else cntcb++;
				}
				else if(v[i]==0){
					cntcb = 2;
				}
				else{
					cntcb++;
				}
			}
		}
		if(cntcb>=2){
			cout<<"cslnb"<<endl;
			continue;
		}
		f(n){
			cnt += v[i]-pre;
			pre++;
		}
		if(cnt&1){
			cout<<"sjfnb"<<endl;
		}
		else{
			cout<<"cslnb"<<endl;
		}
	}
}