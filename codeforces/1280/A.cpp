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
string s,real;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        real = s;
        ll cur = 0;
        if(s.size()==1){
            cout<<1<<'\n';
            continue;
        }
        while(real.size() < n){
            int mul = real[cur] - '1';
            string add = real.substr(cur+1);
            while(mul--){
                real += add;
                if(real.size() >= n)break;
            }
            cur++;
        }
        ll ans = s.size();
        for(int i = 0 ; i < n ; i++){
            cur = ans - i - 1;
            cur += mod;
            cur %= mod;
            ans += cur * (real[i]-'1');
            ans %= mod;
        }
        cout << ans << '\n';
    }
}
