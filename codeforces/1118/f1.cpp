#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int b,r;
int c[300005];
int bb[300005];
int rr[300005];
vector<int>g[300005];
int ans = 0;
void dfs(int now,int pre){

    for(auto i:g[now]){
        if(i!=pre){
            dfs(i,now);
            bb[now] += bb[i];
            rr[now] += rr[i];
        }
    }
    if(c[now]==1){
        bb[now]++;
    }
    else if(c[now]==2){
        rr[now]++;
    }
    if(bb[now]==b&&rr[now]==0){
        ans++;
    }
    if(rr[now]==r&&bb[now]==0){
        ans++;
    }
}
int main(){
    int n;
    while(cin>>n){
        f1(n){
            cin >> c[i];
            if(c[i]==1){
                b++;
            }
            else if(c[i]==2){
                r++;
            }
        }
        f(n-1){
            int add1,add2;
            cin >> add1 >> add2;
            g[add1].pb(add2);
            g[add2].pb(add1);
        }
        ans = 0;
        dfs(1,0);
        cout << ans << endl;
    }
}