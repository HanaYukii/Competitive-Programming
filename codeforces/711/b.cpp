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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		ll cont[n+5][n+5] = {};
		int x,y;
		if(n==1){
			cout<<74751<<endl;
			exit(0);
		}
		f1(n){
			fr(j,1,n+1){
				cin >> cont[i][j];
				if(!cont[i][j]){
					x = i;
					y = j;
				}
			}
		}
		ll sum = 0;
		int tar = x % n +1;
		for(int i = 1 ; i <= n ;i++){
			sum += cont[tar][i];
			sum -= cont[x][i];
		}
		cont[x][y] = sum;
		int f = 0;
		ll rs[n+5] = {},cs[n+5] = {},ds[n+5] = {};
		f1(n){
			fr(j,1,n+1){
				rs[i] += cont[i][j];
				cs[j] += cont[i][j];
				if(i==j){
					ds[1] += cont[i][j];
				}
				if(i+j==n+1){
					ds[2] += cont[i][j];
				}
			}
		}
		f1(n-1){
			if(rs[i]!=rs[i+1])f=1;
			if(cs[i]!=cs[i+1])f=1;
		}
		if(ds[1]!=ds[2]){
			f=1;
		}
		if(ds[1]!=cs[1]||cs[1]!=rs[1]){
			f=1;
		}
		if(f||sum<=0){
			cout<<-1<<endl;
		}
		else{
			cout<<sum<<endl;
		}
	}
}