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
	int n,k;
	while(cin >> n >> k){
		int cont[n+5] = {};
		int f = 0;
		int cnt = 0;
		vector<int>v;
		int tot = 0;
		f1(n){
			cin >> cont[i];
			if(cont[i]<0){
				k--;
				f = 1;
			}
			if(f&&cont[i]>=0){
				cnt++;
			}
			if(cont[i]<0&&cont[i-1]>=0){
				tot++;
				if(cnt)
					v.pb(cnt);
				cnt = 0;
			}
			if(cont[i]>=0&&cont[i-1]<0){
				tot++;
			}
		}
		//cout << tot << endl;
		if(k<0){
			cout<<-1<<endl;
			exit(0);
		}
		sort(v.begin(),v.end());
		for(auto i:v){
			//cout << i <<' '<<k<<' '<<tot<< endl;
			if(k>=i){
				tot-=2;
				k -= i;
			}
		}
		if(cnt&&k>=cnt){
			tot--;
		}
		cout << tot << endl;
	}
}