#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v1(n), v2(m);
        int nxt[m+5] = {};
        for (auto &i:v1){
            cin >> i;
        }
        for (auto &i:v2){
            cin >> i;
        }
        int p1 = 0, p2 = -1;
        nxt[0] = -1;
        while(p1 < m){
            if(p2 == -1 || v2[p1] == v2[p2]){
                p1++, p2++, nxt[p1] = p2;
            }
            else{
                p2 = nxt[p2];
            }
        }
        p1 = 0, p2 = 0;
        while(p1 < n && p2 < m){
            if(p2 == -1 || v1[p1] == v2[p2]){
                p1++, p2++;
            }
            else{
                p2 = nxt[p2];
            }
        }
        if(p2 == m){
            cout << p1 - m + 1 <<endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}
