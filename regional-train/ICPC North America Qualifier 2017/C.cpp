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
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int dp[2000005] = {};
    cin >> n;
    vector<int>v(n);
    for(auto &i:v){
        cin >> i;
    }
    f1(2000000){
        dp[i] = i;
    }
    for(auto i:v){
        for(int j = i ; j <= 2000000 ; j++){
            dp[j] = min(dp[j],dp[j-i] + 1);
        }
    }
    for(int i = 1 ; i <= 2000000 ; i++){
        int cnt = 0;
        int rem = i;
        while(rem){
            int u = *prev(upper_bound(v.begin(),v.end(),rem));
            cnt += rem / u;
            rem %= u;
        }
        if(cnt != dp[i]){
            cout << "non-canonical" << endl;
            exit(0);
        }
    }
    cout << "canonical" << endl;
}
