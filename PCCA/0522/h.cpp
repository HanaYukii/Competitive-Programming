#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL MOD(LL x, LL mod) {
    while (x < 0)
        x += mod;
    return x % mod;
}
void minRotate(vector<LL> &data) {
    int n = (int)data.size();
    vector<LL> buf;
    for (auto &v : data)
        buf.push_back(v);
    for (auto &v : data)
        buf.push_back(v);
    int i = 0, j = 1;
    while (i < n && j < n) {
        int k = 0;
        while (k < n && buf[i + k] == buf[j + k])
            k++;
        if (buf[i + k] <= buf[j + k])
            j += k + 1;
        else
            i += k + 1;
        if (i == j)
            j++;
    }
    int ans = i < n ? i : j;
    data.clear();
    for (int i = 0 ; i < n ; i++)
        data.push_back(buf[i + ans]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<LL> data[2];
    for (int x = 0 ; x < 2 ; x++) 
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        data[x].push_back(v);
    }
    sort(data[0].begin(), data[0].end());
    sort(data[1].begin(), data[1].end());
    data[0].push_back(data[0][0]);
    data[1].push_back(data[1][0]);
    vector<LL> diff[2];
    for (int x = 0 ; x < 2 ; x++) {
        for (int i = 0 ; i < n ; i++)
            diff[x].push_back(MOD(data[x][i] - data[x][i + 1], 360000));
    }
    minRotate(diff[0]);
    minRotate(diff[1]);
    
    bool ok = true;
    for (int i = 0 ; i < n ; i++) {
        if (diff[0][i] != diff[1][i])
            ok = false;
    }
    if (ok) {
        cout << "possible\n";
    } else {
        cout << "impossible\n";
    }
}