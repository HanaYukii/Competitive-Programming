#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300006
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
int idx;
int ans[10005][2];
vector<int>g[10005];
void dfs(int now,int pre){
    ans[now][0] = ans[pre][1];
    ans[now][1] = ++idx;
	if(g[now].size()==1&&pre){
		ans[now][1] = ans[pre][0];
	}
    for(auto i:g[now]){
        if(i==pre)continue;
        dfs(i,now);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    f(n-1){
        int add1, add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
	int rt = 0;
	f1(n){
        if(g[i].size()==1){
            rt = i;
            break;
        }
	}
    idx = 1;
    ans[0][1] = 1;
    dfs(rt,0);
    f1(n){
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
    cout << endl;
}


