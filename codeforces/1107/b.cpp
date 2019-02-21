#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;


int main(void){
    ios_base::sync_with_stdio(false);
    ll n,k,t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<(n-1)*9+k<<endl;
    }

}