#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>ans;
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(4);
    ans.push_back(4);
    ans.push_back(7);
    int cont[125];
    int cnt=0;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans.size();j++)
        {
            for(int k=0;k<ans.size();k++)
            {
                cont[cnt++]=ans[i]*ans[j]*ans[k];
            }
        }
    }
    sort(cont,cont+125);
    for(int i=0;i<125;i++)
        cout<<cont[i]<<' ';
    cout<<endl;
}
//1 2 2 2 3 3 3 4 4 4 4 4 4 6 6 6 6 6 6 7 7 7 8 8 8 8 8 8 8 9 9 9 12 12 12 12 12 12 12 12 12 14 14 14 14 14 14 16 16 16 16 16 16 18 18 18 21 21 21 21 21 21 24 24 24 24 24 24 27 28 28 28 28 28 28 28 28 28 32 32 32 36 36 36 42 42 42 42 42 42 48 48 48 49 49 49 56 56 56 56 56 56 63 63 63 64 84 84 84 84 84 84 98 98 98 112 112 112 147 147 147 196 196 196 343



