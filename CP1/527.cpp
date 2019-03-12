#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<long long int,int> mp;
        int n;
        cin>>n;
        for(int i=0; i<n*n*n; i++)
        {
            long long add;
            cin>>add;
            mp[add]++;
        }
        auto it=mp.begin();
        long long ans[n+1]= {0};
        long long tmp=it->first;
        long long first=(long long)(pow(tmp,1.0/3)+0.5);
        //cout<<first<<endl;
        ans[0]=first;
        it->second--;
        if(it->second==0)
            mp.erase(it);
        for(int i=1; i<n; i++)
        {
            for(it=mp.begin(); it!=mp.end(); it++)
            {
                //
                if(it->second!=0)
                {
                    //cout<<it->first<<' '<<it->second<<endl;
                    break;
                }

            }
            long long tmp=it->first;
            ans[i]=tmp/(first*first);
            long long a=ans[i]*ans[i]*ans[i];
            mp[a]-=1;
            //cout<<mp[a]<<endl;
            for(int j=0; j<i; j++)
            {
                for(int k=0; k<=i; k++)
                {
                    long long a=ans[k]*ans[j]*ans[i];
                    //cout<<a<<' ';
                    mp[a]-=3;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
}
