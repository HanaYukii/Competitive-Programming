#include<bits/stdc++.h>
using namespace std;
long long GCD(long long a,long long b)
{
    while((a%=b)&&(b%=a));
    return a+b;
}
int main()
{
    long long a,b;
    int t;
    cin>>t;
    char filename[]="ans.txt";
    fstream fp;
    fp.open(filename, ios::out);
    while(t--)
    {
        cin>>a>>b;
        if(GCD(a,b)!=a)
        {
            puts("-1");
        }
        else
        {
            long long c=b/a;
            c*=GCD(c,a);
            long long k=c;
            long long g=sqrt(k);
            for(int i=2; i<=g; i++)
            {
                if(!(k%i))
                {
                    while(!(k%i))
                    {
                        b/=i;
                        k/=i;

                    }
                    while(!(b%i))
                    {
                        c*=i;
                        b/=i;
                    }
                }
            }
            if(k>1)
            {
                b/=k;
                while(!(b%k))
                {
                    c*=k;
                    b/=k;
                }
            }
            cout<<c<<endl;
            fp<<c<<endl;
        }

    }
}




