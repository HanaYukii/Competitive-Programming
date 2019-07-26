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
#define F first
#define S second
const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int b,w;
		cin >> b >> w;
		int mx = max(b,w);
		int mi = min(b,w);
		if(mx > 3 * mi +1){
			cout<<"NO"<<'\n';
			continue;
		}
		cout <<"YES"<<'\n';
		if(b > w){
			f1(w*2+1){
				cout<<i<<' '<<2<<'\n';
			}
			int dif = b-w-1;
			int cur = 2;
			while(dif){
				cout<<cur<<' '<<1<<'\n';
				dif--;
				if(!dif)break;
				cout<<cur<<' '<<3<<'\n';
				dif--;
				cur += 2;
			}
		}
		else{
			fr(i,2,b*2+2){
				cout<<i<<' '<<3<<'\n';
			}
			int dif = w-b;
			if(dif){
				cout<<1<<' '<<3<<'\n';
				dif--;
			}
			int cur = 2;
			while(dif){
				cout<<cur<<' '<<2<<'\n';
				dif--;
				if(!dif)break;
				cout<<cur<<' '<<4<<'\n';
				cur += 2;
				dif--;
			}
		}
	}
}