#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
vector<int>g[maxn];
int pa[maxn];
int d[maxn];
void dfs(int now, int pre){
    for(auto i:g[now]){
        if(i != pre){
            d[i] = d[now] + 1;
            pa[i] = now;
            dfs(i, now);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    f(n - 1){
        int add1, add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    int ans1 = 1, ans2 = 1, ans3 = 1;
    ms(d);
    dfs(1,0);
    f1(n){
        if(d[i] > d[ans1]){
            ans1 = i;
        }
    }
    ms(d);
    dfs(ans1, 0);
    f1(n){
        if(d[i] > d[ans2]){
            ans2 = i;
        }
    }
    int sum = d[ans2];
    ms(d);
    int cur = ans2;
    
    f1(n){
        if(i != ans1 && i !=ans2){
            ans3 = i;
            break;
        }
    }
    ms1(d);
    queue<int>q;
    while(cur != ans1){
        q.push(cur);
        d[cur] = 0;
        cur = pa[cur];

    }
    q.push(ans1);
    d[ans1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i:g[now]){
            if(~d[i])continue;
            d[i] = d[now] + 1;
            q.push(i);
        }
    }
    f1(n){
        if(d[i] > d[ans3]){
            ans3 = i;
        }
    }
    sum += d[ans3];
    cout << sum << '\n';
    cout << ans1 <<' '<<ans2 <<' '<<ans3 << '\n';

}
