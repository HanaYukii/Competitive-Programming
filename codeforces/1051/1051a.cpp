#include<bits/stdc++.h>
using namespace std;
int dp[431073],cont[230173];
vector<int> tmp;
int n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt[3]={};
        for(auto i:s){
            if(i>='A'&&i<='Z'){
                cnt[0]++;
            }
            else if(i>='0'&&i<='9'){
                cnt[2]++;
            }
            else{
                cnt[1]++;
            }
        }
        int k=0;
        for(int i=0;i<3;i++){
            if(cnt[i])k++;
        }
        if(k==3){
            cout<<s<<endl;
        }
        else if(k==1){
            if(cnt[0]){
                s[0]='a',s[1]='0';
                cout<<s<<endl;
            }
            else if(cnt[1]){
                s[0]='A',s[1]='0';
                cout<<s<<endl;
            }
            else{
                s[0]='A',s[1]='a';
                cout<<s<<endl;
            }
        }
        else{
            if(!cnt[0]){
                if(cnt[1]>1){
                    for(int i=0;i<s.length();i++){
                        if(s[i]>='a'&&s[i]<='z'){
                            s[i]='A';
                            cout<<s<<endl;
                            break;
                        }
                    }
                }
                else{
                    for(int i=0;i<s.length();i++){
                        if(s[i]>='0'&&s[i]<='9'){
                            s[i]='A';
                            cout<<s<<endl;
                            break;
                        }
                    }
                }
            }
            if(!cnt[1]){
                if(cnt[0]>1){
                    for(int i=0;i<s.length();i++){
                        if(s[i]>='A'&&s[i]<='Z'){
                            s[i]='a';
                            cout<<s<<endl;
                            break;
                        }
                    }
                }
                else{
                    for(int i=0;i<s.length();i++){
                        if(s[i]>='0'&&s[i]<='9'){
                            s[i]='a';
                            cout<<s<<endl;
                            break;
                        }
                    }
                }
            }
            if(!cnt[2]){
                if(cnt[0]>1){
                    for(int i=0;i<s.length();i++){
                        if(s[i]>='A'&&s[i]<='Z'){
                            s[i]='0';
                            cout<<s<<endl;
                            break;
                        }
                    }
                }
                else{
                    for(int i=0;i<s.length();i++){
                        if(s[i]>='a'&&s[i]<='z'){
                            s[i]='0';
                            cout<<s<<endl;
                            break;
                        }
                    }
                }
            }
        }
    }
}
