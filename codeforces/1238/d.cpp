#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod =1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    string s;
    while(cin >> n){
        cin >> s;
        ll ans = (n) * (n-1) / 2;
        int sw = 0;
        f1(s.size()-1){
            if(s[i]!=s[i-1])sw++;
        }
        ans += sw;
        f1(s.size()-1){
            if(s[i]!=s[i-1]){
                ans -= n-i;
                break;
            }
        }
        reverse(s.begin(),s.end());
        f1(s.size()-1){
            if(s[i]!=s[i-1]){
                ans -= n-i;
                break;
            }
        }
        cout << ans << endl;
    }
}