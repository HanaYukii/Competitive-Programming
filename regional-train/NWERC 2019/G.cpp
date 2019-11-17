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
#define double long double
const int mod = 1e9 + 7;
const double eps = 1e-9;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n, k;
    cin >> n >> k;
    double v[2*n+5];
    double dp[n+5] = {};
    f1(n){
        cin >> v[i];
        v[i+n] = v[i];
    }
    for(int i = n + 1 ; i <= 2*n ; i++){
        double prob = (double)k/(double)n;
        double ans = 0;
        ans += prob * v[i];
        for(int j = 1 ; j <= n-k ; j++){
            prob *= (n-k-j+1);
            prob /= (n-j);
            ans += prob * v[i-j];
        }
        cout << fixed << setprecision(10) << ans <<' ';
    }
    cout << endl;
}
