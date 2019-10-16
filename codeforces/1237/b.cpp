#include<bits/stdc++.h>

#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
const int maxn = 200005;
int n;
int b[maxn];
int sum(int x){
    int ret = 0;
    while(x){
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
void update(int x){
    while(x<=n){
        b[x]++;
        x += (x) & (-x);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n){
        memset(b,0,sizeof(b));
        map<int,int>mp;
        int add;
        int ans = 0;
        f1(n){
            cin >> add;
            mp[add] = i;
        }
        f1(n){
            cin >> add;
            int idx = mp[add];
            if(sum(idx)!=idx-1){
                ans++;
            }
            update(idx);
        }
        cout << ans << endl;
    }
}