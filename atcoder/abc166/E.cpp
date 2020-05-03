#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int,int>

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int>v;
    f(n) {
        int x;
        cin >> x;
        v.pb(x);
    }
    ll ans = 0;
    map<int,int>mp;
    for (int i = 0 ; i < n ; i++) {
        int x = v[i] - (n - i);
        int tar = i - v[i] - n;
        //cout << x << endl;
        //cout << x <<' '<<tar<< endl;
        if (mp.count(tar)) {
            //cout << tar << endl;
            ans += mp[tar];
        }
        mp[x]++;
    }
    cout << ans << endl;  
}
