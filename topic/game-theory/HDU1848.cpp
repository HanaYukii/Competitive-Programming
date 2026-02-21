#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
vector<int>fib;
int sg[1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fib.push_back(1);
    fib.push_back(2);
    while(1){
        int now = fib.back() + fib[fib.size()-2];
        if(now > 1000)break;
        fib.push_back(now);
    }
    sg[0] = 0;
    for(int i = 1 ; i <= 1000 ; i++){
        unordered_set<int>st;
        for(auto j:fib){
            if(i-j>=0){
                st.insert(sg[i-j]);
            }
        }
        int cur = 0;
        while(st.count(cur))cur++;
        sg[i] = cur;
    }
    int a, b, c;
    while(cin >> a >> b >> c && (a|b|c)){
        int x = sg[a] ^ sg[b] ^ sg[c];
        if(x == 0){
            cout << "Nacci" << '\n';
        }
        else{
            cout << "Fibo" << '\n';
        }
    }

}
