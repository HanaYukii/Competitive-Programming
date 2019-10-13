#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >>t;
    while(t--){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        int nd1 = (a-1)/c+1;
        int nd2 = (b-1)/d+1;
        if(nd1+nd2>e){
            cout<<-1<<'\n';
        }
        else{
            cout<<nd1<<' '<<nd2<<'\n';
        }
    }
}