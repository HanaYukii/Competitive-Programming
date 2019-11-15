#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string v1, v2;
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        string s;
        cin >> s;
        int nxt[m+5] = {};
        int p1 = 0, p2 = -1;
        nxt[0] = -1;
        int ans = m;
        while(p1 < m){
            if(p2 == -1 || s[p1] == s[p2]){
                p1++, p2++, nxt[p1] = p2;
            }
            else{
                p2 = nxt[p2];
            }
        }
        for(int i = 1 ; i <= m ; i++){
            int cur = i;
            while(nxt[cur]){
                ans++;
                cur = nxt[cur];
            }
        }
        cout << ans % 10007 << '\n';
    }
}
