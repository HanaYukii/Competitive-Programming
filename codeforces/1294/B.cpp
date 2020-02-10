#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int> >v(n);
        for(auto &i:v){
            cin >> i.F >> i.S;
        }
        sort(v.begin(),v.end(),[](pair<int,int>x,pair<int,int>y){
            if(x.S == y.S){
                return x.F < y.F;
            }
            else{
                return x.S < y.S;
            }
        });
        string ans;
        int f = 0;
        int x = 0, y = 0;
        for(auto i:v){
            if(i.F < x || i.S < y){
                f = 1;
                break;
            }
            while(x < i.F){
                ans += "R";
                x++;
            }
            while(y < i.S){
                ans += "U";
                y++;
            }
        }
        if(f){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << ans << '\n';
        }
    }
}
