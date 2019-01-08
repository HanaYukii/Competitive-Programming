#include<bits/stdc++.h>
using namespace std;
long long dp[1005][2005][2];
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    while(cin>>n){
        int f=0;
        for(int i=0;i<n;i++){
            int add;
            cin>>add;
            f|=add;
        }
        if(f){
            cout<<"HARD"<<endl;
        }
        else{
            cout<<"EASY"<<endl;
        }
    }
}
