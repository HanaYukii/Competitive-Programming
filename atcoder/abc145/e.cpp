#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n,t;
    cin >> n >> t;
    int dp[6005] = {};
    vector<pair<int,int> >v;
    f(n){
        int add1, add2;
        cin >> add1 >> add2;
        v.pb({add1,add2});
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        int add1=i.F, add2=i.S;
        for(int j = t + add1 - 1 ; j >= add1; j--){
            dp[j] = max(dp[j],dp[j-add1] + add2);
        }
    }
    int mx = 0;
    f(6001){
        mx = max(mx,dp[i]);
    }
    cout << mx << endl;
}
