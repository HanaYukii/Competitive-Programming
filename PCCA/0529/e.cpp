#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    if (s.size() % 2) {
        cout << "NO\n";
    } else {
        map<char, int> cnt;
        int maxV = 0;
        for (auto &c : s)
            cnt[c]++, maxV = max(maxV, cnt[c]);
        if (maxV * 2 > (int)s.size())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}