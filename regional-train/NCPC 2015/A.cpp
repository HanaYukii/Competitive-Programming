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
int v[maxn];
int solve(int now){
    if(!g[now].size())return 0;
    queue<pair<int,int> >q;
    q.push({now,now});
    int last = 0;
    while(!q.empty()){
        pair<int,int>now=q.front();
        q.pop();
        last = now.F;
        for(auto i:g[now.F]){
            if(i!=now.S){
                q.push({i,now.F});
            }
        }
    }
    v[last] = 1;
    queue<int>qq;
    qq.push(last);
    while(!qq.empty()){
        int now = qq.front();
        last = now;
        qq.pop();
        for(auto i:g[now]){
            if(v[i])continue;
            v[i] = v[now] + 1;
            qq.push(i);
        }
    }
    return v[last] - 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    /*if(c==0){
        if(n>=3){
            cout<<2<<endl;
        }
        else if(n==2){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        exit(0);
    }
    if(n==2){
        cout<<1<<endl;
        exit(0);
    }*/
    f(c){
        int add1, add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    vector<int>sz;
    f1(n){
        if(!v[i]){
            sz.pb(solve(i));
        }
    }
    sort(sz.rbegin(),sz.rend());
    if(sz.size()==1){
        cout<<sz[0]<<endl;
    }
    else if(sz.size()==2){
        cout<<max(sz[0],(sz[0]+1)/2 + (sz[1]+1)/2 + 1)<<endl;
    }
    else{
        cout<<max((sz[1]+1)/2+(sz[2]+1)/2+2,max(sz[0],(sz[0]+1)/2 + (sz[1]+1)/2 + 1))<<endl;

    }
}
