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
	int n,k;
	while(cin >> n >> k){
		vector<int>v;
		f(n){
			int add;
			cin >> add;
			v.pb(add);
		}
		int ans=0;
		for(int i=1<<20;i;i>>=1){
			int last = 0;
			int now = k-ans-i;
			int f = 0;
			for(int j=0;j<n;j++){
				int dist=(last-v[j]+k)%k;
				if(dist<=now){
					continue;
				}
				else if(v[j]>last){
					last=v[j];
				}
				else{
					f=1;
					break;
				}
			}
			if(!f){
				ans += i;
			}
		}
		cout<<k-ans<<endl;
	}
}