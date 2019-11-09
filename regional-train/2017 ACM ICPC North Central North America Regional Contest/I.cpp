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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<char,int>mp;
    f(26){
        mp['A'+i] = i;
    }
    mp[' ']=26;
    mp['\'']=27;
    int t;
    cin >> t;
    double per = acos(-1) * 60 / 28;
    string s;
    getline(cin,s);
    while(t--){
        string s;
        getline(cin, s);
        double ans = (double)s.size();
        int last = mp[s[0]];
        for(int i=1;i<s.size();i++){
            int nxt = mp[s[i]];
            int need = (nxt - last + 28)%28;
            need = min(need,28-need);
            ans += (double)need * per / 15.0;
            last = nxt;
        }
        cout << fixed << setprecision(10)<<ans << endl;
    }
}
