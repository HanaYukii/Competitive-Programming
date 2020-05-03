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
    ll a;
    cin >> a;
    for (ll i = -1000 ; i <= 1000 ; i++) {
        for (ll j = -1000 ; j <= 1000 ; j++) {
            ll p1 = pow(i,5);
            ll p2 = pow(j,5);
            if (p1 - p2 == a) {
                cout << i <<' '<<j << '\n';
                exit(0);
            }
        }
    }
}
