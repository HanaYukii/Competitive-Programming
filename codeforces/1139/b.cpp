#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
vector<int>g[maxn];
int v[maxn];
int dfs(int now,int pre){
	v[now]=1;
	int ret=1;
	for(auto i:g[now]){
		if(i!=pre){
			ret+=dfs(i,now);
		}
	}
	return ret;
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		ll cont[n+5] = {};
		f(n)cin >> cont[i];
		ll sum = cont[n-1],now = cont[n-1];
		if(n == 1){
			cout << sum <<endl;
			continue;
		}
		for(int i = n-2 ;i >=0 ;i--){
			if(cont[i] < now){
				sum += cont[i];
				now = cont[i];
			}
			else{
				if(now != 1){
					now--;
					sum += now;
				}
			}
		}
		cout << sum << endl;
	}
}