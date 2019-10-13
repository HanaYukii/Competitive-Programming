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
    int n,k;
    while(cin >> n >> k){
        vector<int>v;
        v.pb(0);
        string s;
        cin >> s;
        int ans = 0;
        f1((int)s.size()-1){
            if(s[i]==s[i-1]){
                ans++;
            }
        }
        ans += k*2;
        ans = min(ans,n-1);
        cout << ans << endl;
    }
}