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
int cnt[maxn];
int u[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, l;
    cin >> n >> m >> x >> l;
    f(m){
        int add1, add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
        cnt[add1]++, cnt[add2]++;
    }
    queue<int>q;
    u[l] = 1;
    q.push(l);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i:g[now]){
            cnt[i]--;
            if(u[i])continue;
            if(cnt[i]*2 <= g[i].size()){
                u[i] = 1;
                q.push(i);
            }
        }
    }
    if(u[x]){
        cout << "leave" << endl;
    }
    else{
        cout << "stay" << endl;
    }
}
