#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        k = min(m - 1, k);
        vector<int>v(n);
        for(auto &i:v){
            cin >> i;
        }
        int mx = 0;
        f(k + 1){
            int rem = k - i;
            int lb = i;
            int rb = n - 1 - rem;
            int to = m - k - 1;
            int mn = 1e9;
            for(int j = 0 ; j <= to ; j++){
                int nlb = lb + j;
                int nrb = rb - to + j;
                mn = min(mn,max(v[nlb],v[nrb]));
            }
            mx = max(mx, mn);
        }
        cout << mx << '\n';
    }
}
