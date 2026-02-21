#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int mod = 1e9 + 7;
int a[MAXN], d[MAXN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(d, 0, sizeof(d));
        memset(a, 0, sizeof(a));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < m; i++){
            int add1, add2;
            cin >> add1 >> add2;
            d[add1]++, d[add2]++;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if(d[i]&1)cnt++;
        }
        if(cnt != 0 && cnt != 2){
            cout << "impossible" << '\n';
            continue;
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            d[i] = (d[i] + 1) / 2;
            if(d[i] & 1){
                ans ^= a[i];
            }
        }
        int tmp = ans;
        if(cnt == 0){
            for(int i = 1 ; i <= n ; i++){
                tmp = max(tmp,ans^a[i]);
            }
            ans = tmp;
        }
        cout << ans << endl;
    }
}
