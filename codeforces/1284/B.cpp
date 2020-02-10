#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
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
    ll n;
    cin >> n;
    ll ans = n * n;
    vector<int>mx;
    vector<vector<int> >v(n);
    f(n){
        int k;
        cin >> k;
        for(int j = 0 ; j < k ; j++){
            int add;
            cin >> add;
            v[i].pb(add);
        }
    }
    f(n){
        int f = 0;
        for(int j = 1 ; j < v[i].size() ; j++){
            if(v[i][j]>v[i][j-1]){
                f = 1;
            }
        }
        if(!f){
            mx.pb(v[i][0]);
        }
    }
    sort(mx.begin(),mx.end());
    f(n){
        int f = 0;
        for(int j = 1 ; j < v[i].size() ; j++){
            if(v[i][j]>v[i][j-1]){
                f = 1;
            }
        }
        if(!f){
            ans -= upper_bound(mx.begin(),mx.end(),v[i].back())-mx.begin() ; 
        }
    }
    cout << ans << '\n';
}
