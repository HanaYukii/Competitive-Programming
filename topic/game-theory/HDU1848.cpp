#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
vector<int>fib;
int sg[1005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fib.pb(1);
    fib.pb(2);
    while(1){
        int now = fib.back() + fib[fib.size()-2];
        if(now > 1000)break;
        fib.pb(now);
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
