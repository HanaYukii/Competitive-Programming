#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));


int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    while(cin>>n>>m){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int now=n;
        for(int i=m;i>=0;i--){
            now+=i;
            if(i==b){
                now-=a;
            }
            if(i==d){
                now-=c;
            }
            now=max(now,0);
        }
        cout<<now<<endl;
    }
    
}