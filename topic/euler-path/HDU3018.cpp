#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int mod = 1e9 + 7;
int d[MAXN];
int cnt[MAXN];
int sz[MAXN];
int odd[MAXN];
int fi(int x){
    return d[x] == x ? x : d[x] = fi(d[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m){
        for(int i = 1 ; i <= n ; i++){
            d[i] = i;
            cnt[i] = 0;
            odd[i] = 0;
            sz[i] = 0;
        }
        for(int i = 1 ; i <= m ; i++){
            int add1, add2;
            cin >> add1 >> add2;
            int x = fi(add1);
            int y = fi(add2);
            cnt[add1]++, cnt[add2]++;
            d[x] = y;
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            sz[fi(i)]++;
            if(cnt[i] & 1){
                odd[fi(i)]++;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(sz[i] <= 1)continue;
            ans += max(1,odd[i] / 2);
        }
        cout << ans << '\n';
    }
}
