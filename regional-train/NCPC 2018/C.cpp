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
    int u[400] = {};
    int n;
    cin >> n;
    f1(n){
        int add;
        cin >> add;
        u[add] = 1;
    }
    int cnt = 0;
    int ans = 0;
    int cur = 0;
    f1(365){
        cur += cnt;
        if(cur >= 20){
            cnt = 0;
            cur = 0;
            ans++;
        }
        cnt += u[i];
    }
    if(cnt){
        ans++;
    }
    cout << ans << endl;
}
