#include<bits/stdc++.h>
using namespace std;
long long dp[1005][2005][2];
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    while(cin>>n){
        string s;
        cin>>s;
        for(int i=0;i<=500;i++){
            int now=0;
            int sum=0;
            int cnt=0;
            while(now<n){
                sum+=s[now]-'0';
                if(sum==i){
                    cnt++;
                    sum=0;
                }
                if(sum>i)
                    break;
                now++;
                if(cnt>=2&&now==n&&sum==0){
                    cout<<"YES"<<endl;
                    exit(0);
                }
            }
        }
        cout<<"NO"<<endl;
    }
}
