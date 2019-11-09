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
int can[5005];
vector<pair<int,int> >start[5005];
map<int,pair<int,int> >g;
int val[20][5005];
int vis[20][5005];
int sz[20];
ll del[20];
pair<int,int>nxt[20][5005];
int n;
int dp(int b){
    if(can[b]==1){
        return 1;
    }
    for(int i=0;i<(1<<n);i++){
        if((b&i)!=i)continue;
        if(dp(i)&&dp(b^i)){
            for(auto j:start[i]){
                start[b].pb(j);
            }
            for(auto j:start[b^i]){
                start[b].pb(j);
            }
            return 1;
        }
    }
    return 0;
}
void solve(int i,int j,int sti,int stj,int b){
    cout<<i<<' '<<j<<' '<<nxt[i][j].F<<' '<<nxt[i][j].S<<' '<<sti<<' '<<stj<<endl;
    if(nxt[i][j].F==-1){
        return;
    }
    if(nxt[i][j].F==sti&&nxt[i][j].S==stj){
        cout<<"here"<<' '<<b<<endl;
        if(can[b])return;
        can[b] = 1;
        start[b].pb({sti,stj});
        return;
    }
    if((1<<(nxt[i][j].F-1))&b){
        return;
    }
    solve(nxt[i][j].F,nxt[i][j].S,sti,stj,b|(1<<(nxt[i][j].F-1)));
}
int main(){
    cin >> n;
    ll sum = 0;
    f1(n){
        int k;
        cin >> k;
        sz[i] = k;
        ll cursum = 0;
        for(int j=0;j<k;j++){
            int add;
            cin >> add;
            val[i][j] = add;
            g[add] = {i,j};
            sum += add;
            cursum += add;
            nxt[i][j] = {-1,-1};
        }
        del[i] = cursum;
    }
    if(sum%n){
        cout<<"No"<<endl;
        exit(0);
    }
    f1(n){
        del[i] -= sum / n;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<sz[i];j++){
            int tar = val[i][j] - del[i];
            if(g.count(tar)){
                pair<int,int>p = g[tar];
                if(p.F!=i||((p.F==i)&&(p.S==j))){
                    nxt[i][j] = {p.F,p.S};
                }
            }
            
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<sz[i];j++){
            solve(i,j,i,j,1<<(i-1));
        }
    }
    int ans[n+5][2];
    if(dp((1<<n)-1)){
        for(auto i:start[(1<<n)-1]){
            
            pair<int,int> now = i;
            while(1){
                ans[now.F][0] = now.S;
                ans[now.F][1] = nxt[now.F][now.S].F;
                now = nxt[now.F][now.S];
                if(now==i)break;
            }
        }
    }
    f1(n){
        cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
    }
}
