#include<bits/stdc++.h>
using namespace std;
struct p
{
    int ind;
    int w;
} cont[200005];
bool cmp(string x,string y)
{
    return x.length()<y.length();
}
int main()
{
    srand(time(NULL));
    int n=1000000;
    int num1=0,num2=0;
    while(n--)
    {
        if(rand()%2)
        {
            num1++;
        }
        else
        {
            num2++;
        }
    }
    cout<<num1<<' '<<num2<<endl;
}
