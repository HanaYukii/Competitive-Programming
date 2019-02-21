#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const int mod=1e9+7;
int main(){
    int n,m;
    while(cin>>n){
        int Max=0;
        int cont[n+5]={};
        f(n){
            cin>>cont[i];
            Max=max(Max,cont[i]);
        }
        int now=0;
        int ans=0;
        f(n){
            if(cont[i]==Max){
                now++;
                ans=max(now,ans);
            }
            else{
                now=0;
            }
        }
        cout<<ans<<endl;
    }
}