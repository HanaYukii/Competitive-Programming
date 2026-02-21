// Binary Indexed Tree (Fenwick Tree)
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
int b[MAXN];
int n;
int sum(int x){
    int ret = 0;
    while(x){
        ret += b[x];
        x -= (x) & (-x);
    }
    return ret;
}
void update(int x){
    while(x <= n){
        b[x]++;
        x += x & (-x);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
}
