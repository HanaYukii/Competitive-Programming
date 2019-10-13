#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(m+1==n){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
    }
}