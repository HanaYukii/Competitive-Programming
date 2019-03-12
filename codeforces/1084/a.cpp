#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int n;
    while(cin>>n){
        int ans=0;
        for(int i=0;i<n;i++){
            int add;
            cin>>add;
            ans+=add*i*4;
        }
        cout<<ans<<endl;
    }
}