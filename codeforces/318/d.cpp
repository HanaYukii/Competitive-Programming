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
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		int cont[505][505] = {};
		queue<pair<int,int> >q;
		cont[250][250] = n;
		if(n>=4)
			q.push({250,250});
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			//cout << x <<' '<<y<<endl;
			int num = cont[x][y];
			int div = num/ 4;
			cont[x][y] %= 4;
			if(cont[x][y+1]+div >= 4 && cont[x][y+1]< 4){
				q.push({x,y+1});
			}
			cont[x][y+1] += div;
			if(cont[x][y-1]+div >= 4 && cont[x][y-1]< 4){
				q.push({x,y-1});
			}
			cont[x][y-1] += div;
			if(cont[x+1][y]+div >= 4 && cont[x+1][y]< 4){
				q.push({x+1,y});
			}
			cont[x+1][y] += div;
			if(cont[x-1][y]+div >= 4 && cont[x-1][y]< 4){
				q.push({x-1,y});
			}
			cont[x-1][y] += div;
		}
		while(m--){
			int add1,add2;
			cin >> add1 >> add2;
			if(abs(add1)>250||abs(add2)>250){
				cout<<0<<'\n';
			}
			else
				cout<<cont[add1+250][add2+250]<<'\n';
		}
		
	}		
}