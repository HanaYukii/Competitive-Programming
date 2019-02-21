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
    int n,m,k;
    while(cin>>n>>m>>k){
        ll cont[n+5]={};
        f(n)cin>>cont[i];
        sort(cont,cont+n);
        ll big=cont[n-1],small=cont[n-2];
        ll comb=big*k+small;
        //cout<<comb<<' '<<big<<' '<<small<<endl;
        cout<<(m/(k+1))*comb+(m%(k+1))*big<<endl;
    }
}