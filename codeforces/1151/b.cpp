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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	while(cin >>n >> m){
		set<int>st[505];
		int b[505][505];
		f1(n){
			fr(j,1,m+1){
				cin>>b[i][j];
				st[i].insert(b[i][j]);
			}
		}
		int xo=0;
		int nz=0;
		f1(n){
			if(st[i].size()!=1){
				nz=i;
			}
			xo^=(*st[i].begin());
		}
		if(xo==0&&nz==0){
			cout<<"NIE"<<endl;
		}
		else if(xo==0&&nz!=0){
			cout<<"TAK"<<endl;
			f1(nz-1){
				for(int j=1;j<=m;j++){
					if(b[i][j]==*st[i].begin()){
						cout<<j<<' ';
						break;
					}
				}
			}

			for(int i=1;i<=m;i++){
				if(b[nz][i]!=*st[nz].begin()){
					cout<<i<<' ';
					break;
				}
			}
			for(int i=nz+1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(b[i][j]==*st[i].begin()){
						cout<<j<<' ';
						break;
					}
				}
			}
			cout<<endl;
		}
		else{
			cout<<"TAK"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(b[i][j]==*st[i].begin()){
						cout<<j<<' ';
						break;
					}
				}
			}
			cout<<endl;
		}
	}

}