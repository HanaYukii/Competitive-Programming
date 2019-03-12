#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    
    ll a,b,c,d;
    while(cin>>a>>b>>c>>d){
        if(a==d&&!(c&&!a)){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}