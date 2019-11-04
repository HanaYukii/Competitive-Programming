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
vector<int>g[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int b[105][105];
    memset(b,0,sizeof(b));
    int idx = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n+i;j++){
            b[i][j] = idx++;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n*2;j++){
            b[n+i][j] = idx++;
        }
    }
    f(n*2){
        fr(j,0,n*2){
            int idx1 = b[i][j];
            int idx2 = b[i+1][j];
            int idx3 = b[i+1][j+1];
            int idx4 = b[i][j+1];
            g[idx1].pb(idx2);
            g[idx2].pb(idx1);
            g[idx1].pb(idx3);
            g[idx3].pb(idx1);
            g[idx1].pb(idx4);
            g[idx4].pb(idx1);
         }
    }
    set<int>tar;
    int ans = 0;
    f(k){
        int add;
        cin >> add;
        tar.insert(add);
    }
    int v[maxn]= {};
    v[0] = 1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i:g[now]){
            if(v[i]||tar.count(i))continue;
            v[i] = 1;
            q.push(i);
        }
    }
    for(auto i:tar){
        for(auto j:g[i]){
            if(!v[j])continue;
            if(!tar.count(j)){
                ans++;
            }
        }
        cout << endl;
    }
    cout << ans << endl;
}
