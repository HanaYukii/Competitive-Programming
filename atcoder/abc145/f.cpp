#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
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
    int n, k;
    cin >> n >> k;
    vector<ll>v;
    v.pb(0);
    f(n){
        ll add;
        cin >> add;
        v.pb(add);
    }
    v.pb(0);
    ll last = 0;
    ll mx = 0;
    ll tot = 0;
    for(auto i:v){
        tot += max(0LL,i-last);
        cout << last <<' '<<i<<endl;
        last = i;
    }
    cout << tot <<endl;
    for(int i = 1 ; i <= n ; i++){
        mx = max(mx,min(v[i]-v[i-1],v[i]-v[i+1]));
        if(i>1&&i<n)
        mx = max(mx,min(v[i-1]-v[i],v[i+1]-v[i]));
    }
    cout << tot - mx << endl; 
}
