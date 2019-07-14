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
const ll mod = 1e9+7;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		int b[n+5][m+5]={};
		f1(n){
			string s;
			cin >> s;
			fr(j,1,m+1){
				if(s[j-1]=='*'){
					b[i][j]=1;
				}
			}
		}
		int sx=0,sy=0;
		for(int i=2;i<=n-1;i++){
			for(int j=2;j<=m+1;j++){
				if(b[i][j]&&b[i-1][j]&&b[i+1][j]&&b[i][j-1]&&b[i][j+1]){
					sx=i;
					sy=j;
				}
			}
		}
		if(!sx){
			cout<<"NO"<<endl;
			continue;
		}
		int nx=sx-1,ny=sy;
		while(b[nx][ny]==1){
			b[nx][ny]=0;
			nx--;
		}
		nx=sx+1,ny=sy;
		while(b[nx][ny]==1){
			b[nx][ny]=0;
			nx++;
		}
		nx=sx,ny=sy+1;
		while(b[nx][ny]==1){
			b[nx][ny]=0;
			ny++;
		}
		nx=sx,ny=sy;
		while(b[nx][ny]==1){
			b[nx][ny]=0;
			ny--;
		}
		int f=0;
		f1(n){
			fr(j,1,m+1){
				if(b[i][j]){
					f=1;
				}
			}
		}
		if(f){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
}