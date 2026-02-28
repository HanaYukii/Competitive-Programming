#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string st;
    for (char c : s) {
        if (st.size() && st.back() == c) {
            st.pop_back();
        }
        else st += c;
    }
    cout << (st.empty() ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
