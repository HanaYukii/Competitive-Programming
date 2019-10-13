#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int c[n+5][n+5] = {};
	int dx[8]={1,2,2,1,-1,-2,-2,-1};
	int dy[8]={2,1,-1,-2,-2,-1,1,2};
	f1(n){
		fr(j,1,n+1){
			if(!c[i][j]){
				c[i][j] = 1;
				queue<pair<int,int> >q;
				q.push({i,j});
				while(!q.empty()){
					int x = q.front().F;
					int y = q.front().S;
					q.pop();
					fr(k,0,8){
						int nx = x + dx[k];
						int ny = y + dy[k];
						if(min(nx,ny)<1||max(nx,ny)>n||c[nx][ny]){
							continue;
						}
						q.push({nx,ny});
						c[nx][ny] = ((c[x][y]-1)^1)+1;
					}
				}
			}
		}
	}
	f1(n){
		fr(j,1,n+1){
			if(c[i][j]==1){
				cout<<'B';
			}
			else{
				cout<<'W';
			}
		}
		cout << endl;
	}
}