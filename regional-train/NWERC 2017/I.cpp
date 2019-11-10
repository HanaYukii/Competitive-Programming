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
    int l;
    int k;
};
bool cmp(s x,s y){
    return x.l - x.k > y.l - y.k;
}
int pre[505][10005];
int dp[505][10005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<s>v;
    int d[1000];
    f1(n){
        int add1,add2;
        cin >> add1 >> add2;
        v.pb({i,add1,add2});
        d[i] = add2;
    }
    sort(v.begin(),v.end(),cmp);
    for(int z = 1 ;z <= n ;z++){
        auto i=v[z-1];
        for(int c = 0 ; c <= m ; c++){
            dp[z][c] = dp[z-1][c];
        }
        for(int j=m-max(i.l-i.k,0);j>=i.k;j--){
            if(dp[z-1][j-i.k] + 1 > dp[z][j]){
                dp[z][j] = dp[z][j-i.k] + 1;
                pre[z][j] = i.idx;
            }
        }
    }
    vector<int>ans;
    int mx = 0,cur = 0;
    f1(m){
        if(dp[n][i] > mx){
            mx = dp[n][i];
            cur = i;
        }
    }
    for(int i=n;i>=1;i--){
        if(pre[i][cur]){
            ans.pb(pre[i][cur]);
            cur -= d[pre[i][cur]];
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(auto i:ans){
        cout << i <<' ';
    }
    cout << endl;
}
