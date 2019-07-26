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
const ll mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int z=1;z<=t;z++){
		int n,m;
		cin >> n >> m;
		int b[n+5][m+5] = {};
		int r[n+5] = {};
		int c[m+5] = {};
		f1(n){
			r[i] = m;
		}
		f1(m){
			c[i] = n;
		}
		f1(n){
			string s;
			cin >> s;
			s= " "+s;
			fr(j,1,m+1){
				if(s[j]=='.'){
					b[i][j] = 0;
				}
				else{
					b[i][j] = 1;
					r[i]--;
					c[j]--;
				}
			}
		}
		int mi = 1e9;
		f1(n){
			fr(j,1,m+1){
				mi = min(mi,r[i]+c[j]-(b[i][j]==0));
			}
		}
		cout << mi <<'\n';
	}
 
}