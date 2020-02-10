#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const int mod = 1e9+7;

int b[maxn << 1];
void update(int x,int d){
    while(x <= 600000){
        b[x] += d;
        x += x & (-x);
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int mi[n+5] = {},mx[n+5] = {};
    int pos[n+5] = {};
    for(int i = m + 1 ; i <= n + m ; i ++){
        pos[i - m] = i;
        update(i,1);
        mi[i - m] = mx[i - m] = i - m; 
    }
    for(int i = m ; i >= 1 ; i--){
        int add;
        cin >> add;
        mi[add] = 1;
        mx[add] = max(mx[add],sum(pos[add]));
        update(pos[add],-1);
        pos[add] = i;
        update(i,1);
    }
    f1(n){
        mx[i] = max(mx[i],sum(pos[i]));
    }
    f1(n){
        cout << mi[i] << ' ' << mx[i] << '\n';
    }
}
