#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
set<int>can;
vector<int> g[maxn];
int c[maxn];
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		ms(c);
		f1(n)g[i].clear();
		can.clear();
		int rt=0;
		f1(n){
			int add1,add2;
			cin >> add1 >> add2;
			c[i]=add2;
			if(add1 == -1){
				rt = i;
			}
			else{
				g[add1].pb(i);
			}
		}
		int fg=0;
		for(int i=1;i<=n;i++){
			int f=0;
			if(!c[i])continue;
			for(auto j:g[i]){
				if(c[j]==0)f=1;
			}
			if(!f){
				cout<<i<<' ';
				fg=1;
			}
		}
		if(!fg){
			cout<<-1<<endl;
		}
		else{
			cout<<endl;
		}
	}
}