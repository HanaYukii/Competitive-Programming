#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
vector<ll>v;
ll k,n;
int F(int x){
	int l=0,r=x;
	int m=r;
	int cnt=0;
	while(l<m&&r<n){
		if(v[r]-v[l]>=k){
			l++,r++;cnt++;
		}
		else{
			r++;
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	while(cin >> n >> k){
			f(n){
				ll add;
				cin >> add;
				v.pb(add);
			}
			sort(v.begin(),v.end());
			int l=1,r=n-1;
			while(r-l>2){
				int a=(r-l)/3;
				int lm=l+a;
				int rm=l+a+a;
				if(F(lm)>F(rm)){
					r=rm;
				}
				else{
					l=lm;
				}
			}
			int Max=0;
			fr(i,l,r+1){
				Max=max(Max,F(i));
			}
			cout<<Max<<endl;
		}
	
}