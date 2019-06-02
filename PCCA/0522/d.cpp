#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int sum[2] = {0};
    for (int i = 0 ; i < 4 ; i++) {
        int v; cin >> v;
        sum[0] += v;
    }
    for (int i = 0 ; i < 4 ; i++) {
        int v; cin >> v;
        sum[1] += v;
    }
    if (sum[0] == sum[1]) {
        cout << "Tie\n";
    } else if (sum[0] < sum[1]) {
        cout << "Emma\n";
    } else {
        cout << "Gunnar\n";
    }
    
    
}