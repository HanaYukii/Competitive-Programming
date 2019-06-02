#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "A 1" << endl;
    } else if (n == 2) {
        cout << "Q 1 1" << endl;
        int v; cin >> v;
        cout << "A " << v << ' ' << 3 - v << endl;
    } else {
        bool even = false;
        if (n % 2 == 0) even = true, n--;
        vector<int> data;
        cout << "Q 1 2" << endl;
        int ret; 
        cin >> ret; data.push_back(ret);
        cin >> ret; data.push_back(ret);
        for (int i = 0 ; i < (n - 3) / 2 ; i++) {
            cout << "Q " << i * 2 + 2 << ' ' << i * 2 + 4 << endl;
            vector<int> buf(3);
            for (auto &v : buf)
                cin >> v;
            if (find(buf.begin(), buf.end(), data.back()) == buf.end())
                swap(data[data.size() - 1], data[data.size() - 2]);
            int forbid = data.back();
            for (auto &v : buf) {
                if (v == forbid)
                    continue;
                data.push_back(v);
            }
        }
        cout << "Q " << n - 1 << ' ' << n << endl;
        
        vector<int> buf(2);
        for (auto &v : buf)
            cin >> v;
        if (find(buf.begin(), buf.end(), data.back()) == buf.end())
            swap(data[data.size() - 1], data[data.size() - 2]);
        int forbid = data.back();
        for (auto &v : buf) {
            if (v == forbid)
                continue;
            data.push_back(v);
        }
        if (even) {
            set<int> app;
            for (int i = 1 ; i <= n + 1 ; i++)
                app.insert(i);
            for (auto &v : data)
                app.erase(v);
            data.push_back(*app.begin());
        }
        cout << "A";
        for (auto &v : data)
            cout << " " << v;
        cout << endl;

    }

}