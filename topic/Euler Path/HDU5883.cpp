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
int a[maxn], d[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ms(d);
        ms(a);
        int n, m;
        cin >> n >> m;
        f1(n){
            cin >> a[i];
        }
        f(m){
            int add1, add2;
            cin >> add1 >> add2;
            d[add1]++, d[add2]++;
        }
        int cnt = 0;
        f1(n){
            if(d[i]&1)cnt++;
        }
        if(cnt != 0 && cnt != 2){
            cout << "impossible" << '\n';
            continue;
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            d[i] = (d[i] + 1) / 2;
            if(d[i] & 1){
                ans ^= a[i];
            }
        }
        int tmp = ans;
        if(cnt == 0){
            for(int i = 1 ; i <= n ; i++){
                tmp = max(tmp,ans^a[i]);
            }
            ans = tmp;
        }
        cout << ans << endl;
    }
}
