#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int Max=0;
    for(int i=0;i<n;i++){
        if(s[i]=='G'){
            Max++;
        }
    }
    int now=0;
    int last=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='G'){
            now++;
            ans=max(ans,min(now+1+last,Max));
        }
        if(s[i]=='S'&&s[i+1]=='G'){
            last=now;
            now=0;
        }
        if(s[i]=='S'&&s[i+1]=='S'){
            last=0;
            now=0;
        }
    }
    ans=max(ans,min(now+1+last,Max));
    cout<<ans<<endl;
}