#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=1e9+7;

int main(){
	int n,m;;
    while(cin>>n>>m){
        ll md[5005]={};
        ll cnt[5005]={};
        f(m){
            ll a,b;
            cin>>a>>b;
            cnt[a]++;
            if(b<a)b+=n;
            if(!md[a]){
                md[a]=b-a;
            }
            else{
                md[a]=min(md[a],b-a);
            }
        }
        f1(n){
            ll mx=0;
            for(int j=1;j<=n;j++){
                if(!cnt[j])continue;
                mx=max(mx,(cnt[j]-1)*n+(j>=i?j-i:j+n-i)+md[j]);
            }
            cout<<mx<<' ';
        }   
        cout<<endl;
    }
}