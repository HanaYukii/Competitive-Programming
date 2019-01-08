#include<bits/stdc++.h>
using namespace std;
long long dp[1005][2005][2];
#define mod 998244353

int main()
{
    ios_base::sync_with_stdio(0);
    long long n,m,k;
    while(cin>>n>>m>>k){
        if(n*m*2%k){
            cout<<"NO"<<endl;
        }
        else{
                long long nn=n;
                long long d=__gcd(n,k);
                k/=d;
                n/=d;
                d=__gcd(m,k);
                m/=d;
                k/=d;
                if(k==1){
                    if(n==nn){
                        m<<=1;
                    }
                    else{
                        n<<=1;
                    }
                }
                cout<<"YES"<<endl;
                cout<<0<<' '<<0<<endl;
                cout<<0<<' '<<m<<endl;
                cout<<n<<' '<<0<<endl;
            
        }
    }
}