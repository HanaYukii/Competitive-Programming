#include<bits/stdc++.h>
using namespace std;

int cont[100005];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>cont[i];
    sort(cont,cont+n);
    int cnt=0;
    if(cont[0]!=0)
        cnt=1;
    for(int i=1;i<n;i++)
    {
        if(cont[i]!=cont[i-1]&&cont[i]!=0)
            cnt++;
    }
    cout<<cnt<<endl;
}