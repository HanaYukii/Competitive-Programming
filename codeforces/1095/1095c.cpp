#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll cont[maxn];
int main(){
    int g[32]={};
    int n,m;
    cin>>n>>m;
    for(int i=1;i<32;i++){
        g[i]=(1<<i)-1;
    }
    if(m>n||__builtin_popcount(n)>m){
        cout<<"NO"<<endl;
    }
    else{
        n-=m;
        int left=m;
        cout<<"YES"<<endl;
        for(int i=31;i>0;i--){
            int num=n/g[i];
            n%=g[i];
            left-=num;
            for(int j=0;j<num;j++){
                cout<<(1<<i)<<' ';
            }
        }
        for(int i=0;i<left;i++){
            cout<<1<<' ';
        }
        cout<<endl;
    }
}