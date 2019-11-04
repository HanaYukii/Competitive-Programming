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
#define F first
#define S second
struct s{
    int idx;
    ll val;
};
bool cmp(s x,s y){
    return x.val < y.val;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<s>v;
    f(n){
        int add;
        cin >> add;
        v.pb({i,add});
    }
    sort(v.begin(),v.end(),cmp);
    ll dp[n][3] = {};
    dp[0][1] = dp[0][2] = -1e9;
    int from[n][3] = {};
    ll sum = 0;
    for(int i=1;i<n;i++){
        ll del = v[i].val - v[i-1].val;
        sum += del;
        from[i][0] = 2;
        dp[i][0] = dp[i-1][2] + del;
        from[i][1] = 0;
        dp[i][1] = dp[i-1][0];
        if(dp[i-1][2] > dp[i-1][1]){
            from[i][2] = 2;
        }
        else{
            from[i][2] = 1;
        }
        dp[i][2] = max(dp[i-1][2],dp[i-1][1]);
    }
    ll mx = dp[n-1][2],ptr = 2;
    vector<int>sp;
    for(int i=n-1;i>=1;i--){
        if(ptr==0){
            sp.pb(i);
        }
        ptr = from[i][ptr];
    }
    int ans[n+5]={};
    int idx = 1;
    sp.pb(n);
    cout <<sum-mx<<' '<<sp.size()<<endl;
    int now = 0;
    sort(sp.begin(),sp.end());
    for(int i=0;i<sp.size();i++){
        for(int j=now;j<sp[i];j++){
            ans[v[j].idx]=idx;
        }
        idx++;
        now = sp[i];
    }
    f(n){
        cout << ans[i]<<' ';
    }
    cout << endl;
}
