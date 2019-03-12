#include<iostream>
using namespace std;

int main()
{
    bool a[1000];
    for(int i=0;i<1000;i++)
    {
        a[i]=0;
    }
    char s[10000][4];
    int re=0,cnt=0;
    for(int i=123;i<10000;i++)
    {
        int th,hu,ten,one;
        one=i%10;
        ten=i/10;
        hu=ten/10;
        ten%=10;
        th=hu/10;
        hu%=10;

        if(ten!=one&&ten!=th&&ten!=hu&&one!=hu&&one!=th&&th!=hu)
        {
            s[cnt][0]=one;
            s[cnt][1]=ten;
            s[cnt][2]=hu;
            s[cnt++][3]=th;
        }

    }
    cout<<cnt<<endl;
}
