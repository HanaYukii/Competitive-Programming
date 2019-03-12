#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long double a2,a1,a0,b2,b1,b0,R;
        cin>>a2>>a1>>a0>>b2>>b1>>b0>>R;
        R*=acos(-1)*2.0;
        long double l=0,r=1e+20;
        int t=1000;
        while(t--&&(r>l+0.00000001))
        {

            long double m=(l+r)/2.0;
            long double d=(1/3.0)*(a2-b2)*m*m*m+(1/2.0)*(a1-b1)*m*m+(a0-b0)*m;
            if(d>=R)
            {
                r=m;
            }
            else
            {
                l=m+0.000000005;
            }
        }
        cout<<fixed<<setprecision(10)<<l<<endl;
    }
}
