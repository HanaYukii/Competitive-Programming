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
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int sum = 0, mx = 0;
        vector<int>v(3);
        f(3){
            int add;
            cin >> add;
            sum += add;
            v[i] = add;
            mx = max(mx, add);
        }
        int add;
        cin >> add;
        sum += add;
        if(sum % 3){
            cout << "NO\n";
            continue;
        }
        sum /= 3;
        if(mx > sum){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}
