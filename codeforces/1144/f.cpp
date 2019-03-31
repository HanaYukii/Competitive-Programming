#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int v[maxn];
vector<int>g[maxn];
int b;
void dfs(int now){
    for(auto i:g[now]){
        if(v[i]==-1){
            v[i]=!v[now];
            dfs(i);
        }
        else{
            if(v[i]==v[now]){
                b=0;
            }
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin >> n >> k){
		vector<int>e;
		f(k){
			int add1,add2;
			cin >> add1 >> add2;
			g[add1].pb(add2);
			g[add2].pb(add1);
			e.pb(add1);
		}
		memset(v,-1,sizeof(v));
		b = 1;
		v[1]=1;
		dfs(1);
		if(!b){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(auto i:e){
				if(v[i]){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			cout<<endl;
		}
	}


}