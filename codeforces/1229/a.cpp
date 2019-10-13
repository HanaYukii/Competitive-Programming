#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define maxn 2000005
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
	cin >> n;
	int g[n+5][n+5] = {};
	ll cont[n+5] = {};
	ll val[n+5] = {};
	int deg[n+5]={};
	ll sum = 0;
	f1(n)cin >> cont[i];
	f1(n){
		fr(j,1,n+1){
			if(i==j)continue;
			if((cont[i]^cont[j])&cont[i]){
				g[i][j] = 1;
				deg[i]++;
			}
		}
	}
	f1(n){
		cin >> val[i];
		sum += val[i];
	}
	queue<int>q;
	int fin[n+5] = {};
	int left = n-1;
	f1(n){
		if(deg[i]==left){
			fin[i] = 1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		sum -= val[cur];
		left--;
		for(int i=1;i<=n;i++){
			if(fin[i]||i==cur)continue;
			if(g[i][cur])
				deg[i]--;
			if(deg[i]>=left){
				q.push(i);
				fin[i] = 1;
			}
		}
	}
	cout << sum << endl;
}
