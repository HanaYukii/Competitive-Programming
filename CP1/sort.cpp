#include<bits/stdc++.h>
using namespace std;
string s[66];
int main()
{
    for(int i=0; i<66; i++)
    {
        getline(cin,s[i]);
    }
    sort(s,s+66);
    cout<<endl<<endl;
    for(int i=0; i<66; i++)
    {
        cout<<s[i]<<endl;
    }

    system("PAUSE");
}
