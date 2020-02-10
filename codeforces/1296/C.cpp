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
    int t;
    cin >> t;
    while(t--){
        int p1 = 0, p2 = 0;
        int n;
        cin >> n;
        map<pair<int,int>,int> mp;
        string s;
        cin >> s;
        int cnt = 0;
        int mi = 1e7;
        int ans1 = 0;
        mp[{0,0}] = 0;
        for(auto i:s){
            cnt++;
            if(i=='L'){
                p1++;
            }
            else if(i=='R'){
                p1--;
            }
            else if(i=='U'){
                p2++;
            }
            else{
                p2--;
            }
            if(mp.count({p1,p2})){
                if(cnt - mp[{p1,p2}] < mi){
                    mi = cnt - mp[{p1,p2}];
                    ans1 = mp[{p1,p2}];
                }
            }
            mp[{p1,p2}] = cnt;
        }
        if(mi == 1e7){
            cout << -1 << '\n';
        }
        else{
            cout << ans1 + 1 <<' '<<ans1 + mi << '\n';
        }
    }
}
