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
int n;
int b[maxn];
void update(int x){
    while(x<=n){
        b[x]++;
        x += x&(-x);
    }
}
int sum(int x){
    int ret = 0;
    while(x){
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
map<int,int>mp;
ll solve(vector<int>v1,vector<int>v2){
    ll ret = 0;
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        mp[v1[i]]=i+1;
    }
    for(auto i:v2){
        int cur = mp[i];
        ret += sum(cur);
        update(cur);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>v1,v2,v3;
    cin >> n;
    f(n){
        int add;
        cin >> add;
        v1.pb(add);
    }
    f(n){
        int add;
        cin >> add;
        v2.pb(add);
    }
    f(n){
        int add;
        cin >> add;
        v3.pb(add);
    }
    ll ans = 0;
    ans += solve(v1,v2);
    ans += solve(v1,v3);
    ans += solve(v2,v3);
    ll tot = (ll)n*(n-1)/2;
    ll num = (tot * 3 - ans)/2;
    cout << tot - num <<endl;
}
