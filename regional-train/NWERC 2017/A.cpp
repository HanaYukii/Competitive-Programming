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
map<int,int>mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int last = 0;
    vector<int>v;
    f(n){
        int add;
        cin >> add;
        if(add != last){
            mp[add];
            v.pb(add);
            last = add;
        }
    }
    int idx = 1;
    for(auto &i:mp){
        i.S = idx++;
    }
    for(auto &i:v){
        i = mp[i];
    }
    vector<int>can[n+5];
    map<int,int>cnt;
    for(auto i:v){
        cnt[i]++;
    }
    for(int i=1;i<v.size();i++){
        //cout << v[i] << ' '<<v[i-1]<<endl;
        if(v[i]==v[i-1]+1){
            can[v[i]].pb(i);
        }
    }
    int dp[n+5][4] = {};
    int mx = 0;
    for(int i=2;i<idx;i++){
        for(int j=0;j<3;j++){
            if(can[i].size()<=j){
                dp[i][j] = 0;
            }
            else{                    
                dp[i][j] = dp[i-1][3] + 1;
                fr(k,0,3){
                    if(can[i-1].size()<=k)continue;
                    if(cnt[i-1]==1){
                        dp[i][j] = max(dp[i][j],dp[i-1][k]+1) ;
                    }
                    if(can[i-1][k] +1 != can[i][j]){
                        dp[i][j] = max(dp[i][j],dp[i-1][k]+1);
                    }
                    
                }
            }
        }
        dp[i][3] = max({dp[i-1][1],dp[i-1][0],dp[i-1][2],dp[i-1][3]});
        mx = max(mx,max({dp[i][0],dp[i][1],dp[i][2],dp[i][3]}));
    }
    cout << v.size() - 1 - mx << endl;
}
