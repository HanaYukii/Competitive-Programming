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
int gap[6];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,x,y,d;
        cin>>n>>x>>y>>d;
        if(abs(x-y)%d&&(y-1)%d&&(n-y)%d){
            cout<<-1<<endl;
            continue;
        }
        ll Min=1e18;
        if(!(abs(x-y)%d)){
            cout<<abs(x-y)/d<<endl;
        }
        else{
            if(!((y-1)%d)){
                Min=min(Min,(x-2)/d+1+(y-1)/d);
            }
            if(!((n-y)%d)){
                Min=min(Min,(n-x-1)/d+1+(n-y)/d);
            }
            cout<<Min<<endl;
        }
    }
}