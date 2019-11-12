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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll>v;
    f(n){
        ll add;
        cin >> add;
        v.pb(add);
    }
    sort(v.begin(),v.end());
    f(n-2){
        if(v[i] + v[i+1] > v[i+2]){
            cout << "possible" << endl;
            exit(0);
        }
    }
    cout << "impossible" << endl;
}
