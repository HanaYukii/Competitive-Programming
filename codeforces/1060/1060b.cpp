#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    string s;
    while(cin>>s){
        if((int)s.length()==1){
            cout<<s<<endl;
            continue;
        }
        int ans=0;
        int f=0;
        for(int i=(int)s.length()-1;i>0;i--){
            if(!f&&s[i]=='9'){
                ans+=9;
            }
            else if(f){
                ans+=s[i]-'0'+9;
            }
            else{
                ans+=s[i]-'0'+10;
            }
            if(s[i]!='9'){
                f=1;
            }
        }
        if(!f){
            ans+=s[0]-'0';
        }
        else{
            ans+=s[0]-'1';
        }
        cout<<ans<<endl;
    }
}