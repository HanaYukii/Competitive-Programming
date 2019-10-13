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
	int n,l,r;
	while(cin >> n >> l >> r){
		int cont[n+5] = {};
		f1(n){
			cin >> cont[i];
		}
		f1(n){
			int f = 0;
			for(int j = max(i-l,1);j<=min(i+r,n);j++){
				if(cont[j]<cont[i])f=1;
			}
			if(!f){
				cout<<i<<endl;
				exit(0);
			}
		}
	}
}