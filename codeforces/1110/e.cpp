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
    int n;
    while(cin>>n){
        ll s[n+5]={},t[n+5]={};
        f(n)cin>>s[i];
        f(n)cin>>t[i];
        vector<int>d1,d2;
        f1(n-1){
            d1.pb(s[i]-s[i-1]);
            d2.pb(t[i]-t[i-1]);
        }
        sort(d1.begin(),d1.end());
        sort(d2.begin(),d2.end());
        if(d1==d2&&s[0]==t[0]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}