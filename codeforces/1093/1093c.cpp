#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll cont[maxn];
ll ans[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int n;
    while(cin>>n){
        for(int i=0;i<n/2;i++){
            cin>>cont[i];
        }
        ans[n/2-1]=cont[n/2-1]/2;
        ans[n/2]=cont[n/2-1]-ans[n/2-1];
        int l=n/2-2;
        int r=n/2+1;
        for(int i=n/2-2;i>=0;i--){
            if(cont[i]==cont[i+1]){
                ans[l]=ans[l+1];
                ans[r]=ans[r-1];
            }
            else if(cont[i]>cont[i+1]){
                ans[l]=ans[l+1];
                ans[r]=ans[r-1]+cont[i]-cont[i+1];
            }
            else{
                ans[l]=ans[l+1]+cont[i]-cont[i+1];;
                ans[r]=ans[r-1];  
            }
            l--;
            r++;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<' ';
        }    
        cout<<endl;
    }
}