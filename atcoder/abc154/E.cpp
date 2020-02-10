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
string s;
int k;
ll dp[105][2][4];
int a[105];
ll dfs(int pos,int lim,int cur){
    if(cur > k)return 0;
    if(pos == -1 && cur == k){
        return 1;
    }
    else if(pos == -1){
        return 0;
    }
    if(~dp[pos][lim][cur])return dp[pos][lim][cur];
    int ub = lim ? a[pos] : 9;
    ll ans = 0;
    for(int i = 0 ; i <= ub ; i ++){
        ans += dfs(pos-1,lim&&i==ub,cur+(i!=0));
    }
    return dp[pos][lim][cur] = ans;
}
ll solve(){
    cin >> s >> k;
    memset(dp, -1, sizeof(dp));
    int pos;
    pos = 0;
    while(s.size()){
        a[pos] = s.back() - '0';
        s.pop_back();
        pos++;
    }
    return dfs(pos-1,1,0);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << solve() << '\n';
}
