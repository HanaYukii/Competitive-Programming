#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll cont[1005];
int main(){
    
    int n;
    while(cin>>n){
        vector<int>s;
    f(n){
        int add;
        cin>>add;
        s.pb(add);
    }
    sort(s.begin(),s.end());
    int ans=1e9;
    int Min=1e9,Max=0;
    for(int i=0;i<n-1;i++){
        Min=min(Min,s[i]);
        Max=max(Max,s[i]);
    }
    ans=min(ans,Max-Min);
    Min=1e9,Max=0;
    for(int i=1;i<n;i++){
        Min=min(Min,s[i]);
        Max=max(Max,s[i]);
    }
    ans=min(ans,Max-Min);
    cout<<ans<<endl;
    }
}