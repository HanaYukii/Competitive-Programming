#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
const int maxn=1005;
int b[maxn][maxn];
unordered_map<int,int>mpc[maxn];
unordered_map<int,int>mpr[maxn];
set<int>c[maxn];
set<int>r[maxn];
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	while(cin>>n>>m){
		f(n){
			fr(j,0,m){
				cin>>b[i][j];
			}
		}
		f(n){
			fr(j,0,m){
				r[i].insert(b[i][j]);
				c[j].insert(b[i][j]);
			}
		}
		f(n){
			int cnt=1;
			for(auto j:r[i]){
				mpr[i][j]=cnt++;
			}
		}
		f(m){
			int cnt=1;
			for(auto j:c[i]){
				mpc[i][j]=cnt++;
			}
			
		}
		f(n){
			fr(j,0,m){
				if(mpc[j][b[i][j]]>mpr[i][b[i][j]]){
					cout<<max(c[j].size(),mpc[j][b[i][j]]-mpr[i][b[i][j]]+r[i].size())<<' ';
				}
				else{
					cout<<max(r[i].size(),mpr[i][b[i][j]]-mpc[j][b[i][j]]+c[j].size())<<' ';
				}
			}
			cout<<'\n';
		}
	}
}