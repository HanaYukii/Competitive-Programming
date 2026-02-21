// String Hashing (rolling hash)
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
long long mul = 114115;
long long h[MAXN];
long long p[MAXN];

void build(string s){
    long long cur = 0;
    long long now = mul;
    p[0] = 1;
    for (int i = 1 ; i <= s.size() ; i++){
        p[i] = now;
        now *= mul;
        now %= mod;
    }
    for (int i = 1 ; i <= (int)s.size() ; i ++){
        cur *= mul;
        cur += s[i-1];
        cur %= mod;
        h[i] = cur;
    }
}
long long query(int l,int r){
    long long ret = (h[r] - (h[l-1] * p[r - l + 1] % mod) + mod) % mod;
    return ret;
}

int main() {
    // string hash
    string s;
    cin >> s;
    build(s);
    s = " " + s;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    // string 1-based 
    if (query(l1, r1) == query(l2, r2)) {
        cout << "SAME\n";
    }
    else {
        cout << "DIFFERENT\n";
    }
}