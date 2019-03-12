#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int dp[5005][5005];
vector<int>s;
int solve(int l,int r){
    if(l>r)return 0;
    if(dp[l][r]>=0)return dp[l][r];
    if(s[l]==s[r]){
        return dp[l][r]=solve(l+1,r-1)+1;
    }
    else{
        return dp[l][r]=min(solve(l+1,r),solve(l,r-1))+1;
    }
}
int main(){
    
    int n;cin>>n;
    
    char add,pre;
    cin>>add;
    s.push_back(add-'a');
    pre=add;
    f1(n-1){
        char add;
        cin>>add;
        if(add!=pre){
            s.push_back(add-'a');
            pre=add;
        }
    }
    n=s.size();
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)dp[i][i]=0;
    //solve()
    cout<<solve(0,n-1)<<endl;
}