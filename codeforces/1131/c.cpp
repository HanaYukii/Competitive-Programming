#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
const int maxn=150005;
int d[maxn];
int fi(int x){
    return d[x]==x?x:d[x]=fi(d[x]);
}
int main(){
    int n;
    while(cin>>n){
        vector<int>now[n+5]={};
        f1(n){
            now[i].pb(i);
            d[i]=i;
        }
        f(n-1){
            int add1,add2;
            cin>>add1>>add2;
            int x=fi(add1);
            int y=fi(add2);
            d[x]=y;
            for(auto i:now[x]){
                now[y].pb(i);
            }
            now[x].clear();
            now[x].shrink_to_fit();
            if(i==n-2){
                for(auto i:now[y]){
                    cout<<i<<' ';
                }
            }
        }
        cout<<endl;
    }
}