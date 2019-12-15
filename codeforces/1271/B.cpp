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
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int>ans;
    vector<int>v;
    for(auto i:s){
        if(i=='B'){
            v.pb(0);
        }
        else{
            v.pb(1);
        }
    }
    f(n-1){
        if(v[i]==0){
            ans.pb(i+1);
            v[i]^=1;
            v[i+1]^=1;
        }
    }
    if(v[n-1]==1){
        cout << ans.size() << '\n';
        for(auto i:ans){
            cout << i << ' '; 
        }
        cout << '\n';
        exit(0);
    }
    f(n-1){
        if(v[i]==1){
            ans.pb(i+1);
            v[i]^=1;
            v[i+1]^=1;
        }
    }
    if(v[n-1]==0){
        cout << ans.size() << '\n';
        for(auto i:ans){
            cout << i <<' '; 
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}
