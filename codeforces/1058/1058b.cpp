#include<bits/stdc++.h>
using namespace std;
long long dp[1005][2005][2];
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;
    while(cin>>n>>k){
        int t;
        cin>>t;
        while(t--){
            int a,b;
            cin>>a>>b;
            if(b>=a-k&&b>=-a+k&&b<=a+k&&b<=-a+2*n-k){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}
