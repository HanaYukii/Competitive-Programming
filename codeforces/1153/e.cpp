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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n){
		vector<int>x,y;
		f1(n){
			int add;
			cout<<'?'<<' '<<1<<' '<<i<<' '<<n<<' '<<i<<endl;
			cin >> add;
			if(add&1){
				y.pb(i);
			}
			cout<<'?'<<' '<<i<<' '<<1<<' '<<i<<' '<<n<<endl;
			cin >> add;
			if(add&1){
				x.pb(i);
			}
		}
		if(x.size()==2&&y.size()==2){
			cout<<'?'<<' '<<x[0]<<' '<<y[0]<<' '<<x[0]<<' '<<y[0]<<endl;
			int add;
			cin >> add;
			if(add&1){
				cout<<'!'<<' '<<x[0]<<' '<<y[0]<<' '<<x[1]<<' '<<y[1]<<endl;
			}
			else{
				cout<<'!'<<' '<<x[0]<<' '<<y[1]<<' '<<x[1]<<' '<<y[0]<<endl;
			}
		}
		else if(x.size()==2){
			int ans=0;
			for(int i=1<<10;i;i>>=1){
				if(ans+i<=n){
					cout<<'?'<<' '<<x[0]<<' '<<1<<' '<<x[0]<<' '<<ans+i<<endl;
					int add;
					cin >> add;
					if(!(add&1)){
						ans+=i;
					}
				}
			}
			cout<<'!'<<' '<<x[0]<<' '<<ans+1<<' '<<x[1]<<' '<<ans+1<<endl;
		}
		else{
			int ans=0;
			for(int i=1<<10;i;i>>=1){
				if(ans+i<=n){
					cout<<'?'<<' '<<1<<' '<<y[0]<<' '<<ans+i<<' '<<y[0]<<endl;
					int add;
					cin >> add;
					if(!(add&1)){
						ans+=i;
					}
				}
			}
			cout<<'!'<<' '<<ans+1<<' '<<y[0]<<' '<<ans+1<<' '<<y[1]<<endl;
		}
	}

}