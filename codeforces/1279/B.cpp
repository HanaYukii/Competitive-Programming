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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int>v(n);
        for(auto &i:v){
            cin >> i;
        }
        int mx = 0;
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += v[i];
            mx = max(mx,v[i]);
            if(sum <= s){
                ans = i + 1;
            }
            else if(sum - mx <= s){
                ans = i;
            }
            else{
                break;
            }
        }
        if(ans == n){
            cout << 0 << '\n';
        }
        else{
            mx = 0;
            sum = 0;
            f(ans){
                sum += v[i];
                if(v[i] > v[mx]){
                    mx = i;
                }
            }
            if(sum <= s){
                cout << 0 << '\n';
            }
            else{
                cout << mx + 1 << '\n';
            }
        }
    }
}
