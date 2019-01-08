#include<bits/stdc++.h>
using namespace std;
int dp[431073],cont[230173];
vector<int> tmp;
int n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    while(cin>>n){
        map<int,int>mp;
        int cont[105];
        for(int i=0;i<n;i++){
            cin>>cont[i];
            mp[cont[i]]++;
        }
        int cnt1=0,cnt3=0;
        for(auto i:mp){
            if(i.second==1){
                cnt1++;
            }
            else if(i.second>2){
                cnt3++;
            }
        }
        if(cnt1&1&&cnt3==0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        if((cnt1&1)==0){
            int f=0;
            for(int i=0;i<n;i++){
                if(mp[cont[i]]==1&&f){
                    f=0;
                    cout<<'A';
                }
                else if(mp[cont[i]]==1&&!f){
                    f=1;
                    cout<<'B';
                }
                else{
                    cout<<'B';
                }
            }
        }
        else{
            int f=0,f2=0;
            for(int i=0;i<n;i++){
                if(mp[cont[i]]==1&&f){
                    f=0;
                    cout<<'A';
                }
                else if(mp[cont[i]]==1&&!f){
                    f=1;
                    cout<<'B';
                }
                else if(mp[cont[i]]>2&&!f2){
                    cout<<'A';
                    f2=1;
                }
                else{
                    cout<<'B';
                }
            }
        }
    }
}
