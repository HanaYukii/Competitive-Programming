#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string v1, v2;ll
    while(cin >> v1 >> v2){
        int n, m;
        int f = 0;
        if(v1.size() < v2.size()){
            cout << "no" << '\n';
            continue;
        }
        v1 += v1;
        n = v1.size();
        m = v2.size();
        int nxt[m+5] = {};
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
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }
     }
}
