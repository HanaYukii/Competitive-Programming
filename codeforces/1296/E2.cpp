#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>c;
    vector<int>last[26];
    int cur = 1;
    for(int i = 0 ; i < n ; i++){
        int nd = s[i] - 'a';
        int f = 0;
        for(int j = nd; j >= 0 ; j--){
            if(last[j].size()){
                c.pb(last[j].back());
                last[j].pop_back();
                last[nd].push_back(c.back());
                f = 1;
                break;
            }
        }
        if(!f){
            c.pb(cur++);
            last[nd].pb(c.back());
        }
    }
    cout << cur -1 << '\n';
    for(auto i:c){
        cout << i << ' ';
    }
    cout << '\n';
}
