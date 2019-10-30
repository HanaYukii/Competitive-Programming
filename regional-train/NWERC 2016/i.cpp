#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define ms1(i) memset(i,-1,sizeof(i))
#define F first
#define S second
vector<int>g[maxn];
vector<int>rev[maxn];
int d[maxn];
int d1[maxn],d2[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    vector<int>v1,v2;
    f(a){
        int add;
        cin >> add;
        v1.pb(add);
    }
    f(b){
        int add;
        cin >> add;
        v2.pb(add);
    }
    f1(n){
        int k;
        cin >> k;
        while(k--){
            int add;
            cin >> add;
            g[i].pb(add);
            rev[add].pb(i);
        }
    }
    ms1(d),ms1(d1),ms1(d2);
    queue<int>q;
    q.push(1);
    d[1] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i:g[now]){
            if(~d[i])continue;
            d[i] = d[now] + 1;
            q.push(i);
        }
    }
    for(auto i:v1){
        d1[i] = 0;
        q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i:rev[now]){
            if(~d1[i])continue;
            d1[i] = d1[now] + 1;
            q.push(i);
        }
    }
    for(auto i:v2){
        d2[i] = 0;
        q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i:rev[now]){
            if(~d2[i])continue;
            d2[i] = d2[now] + 1;
            q.push(i);
        }
    }
    int mi = 1e9;
    f1(n){
        if(~d1[i]&&~d2[i]&&~d[i]){
            mi = min(mi,d1[i]+d2[i]+d[i]);
        }
    }
    if(mi == 1e9){
        cout<<"impossible"<<'\n';
    }
    else{
        cout<<mi-1<<'\n';
    }
}
