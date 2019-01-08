#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int v[300005];
vector<int>g[300005];
int pm[maxn];
int b;
int cnt;
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cout<<(char)('a'+(i%k));
        }
        cout<<endl;
    }
}