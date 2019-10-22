#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
int d[maxn];
int sz[maxn];
int fi(int x){
    return d[x] == x ? x : d[x] = fi(d[x]); 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        f1(n){
            d[i] = i;
        }
        f1(n){
            int add;
            cin >> add;
            int x = fi(i);
            int y = fi(add);
            d[x] = y;
        }
        f1(n){
            sz[i] = 0;
        }
        f1(n){
            sz[fi(i)]++;
        }
        f1(n){
            cout<<sz[fi(i)]<<' ';
        }
        cout<<'\n';
    }
}
