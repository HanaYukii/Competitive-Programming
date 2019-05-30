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
	int n,m;
	while(cin >> n >> m){
		int cont[n+5][m+5] = {},cont2[n+5][m+5] = {};
		f(n){
			fr(j,0,m){
				cin >> cont[i][j];
			}
		}
		f(n){
			fr(j,0,m){
				cin >> cont2[i][j];
				if(cont[i][j]>cont2[i][j]){
					swap(cont[i][j],cont2[i][j]);
				}
			}
		}
		int f=0;
		f(n){
			fr(j,0,m){
				if(j!=0){
					if(cont[i][j]<=cont[i][j-1]){
						f=1;
					}
					if(cont2[i][j]<=cont2[i][j-1]){
						f=1;
					}
				}
				if(i!=0){
					if(cont[i][j]<=cont[i-1][j]){
						f=1;
					}
					if(cont2[i][j]<=cont2[i-1][j]){
						f=1;
					}
				}
			}
		}
		if(f){
			cout<<"Impossible"<<endl;
		}
		else{
			cout<<"Possible"<<endl;
		}
	}
}