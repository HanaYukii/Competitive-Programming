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
int idx = 0;
map<string,int>mp;
int c[10005];
int cc[1000005];
int pp[1000005];
int p[10005];
int in[10005];
bool e[1000005];
vector<pair<int,int> >g[10005];
int getid(string s){
    if(!mp.count(s)){
        mp[s]=++idx;
        c[idx]=1e9;
        p[idx]=-1e9;
    }
    return mp[s];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s1[k+5],s2[k+5],s3[k+5];
    f(k){
        cin >> s1[i] >> s2[i] >> s3[i] >> cc[i] >> pp[i];
        int x = getid(s1[i]);
        int y = getid(s2[i]);
        int z = getid(s3[i]);
        g[y].pb({z,i});
        g[z].pb({y,i});
        e[i] = 0;
        in[x]++;
    }
    queue<int>q;
    f1(idx){
        if(!in[i]){
            c[i]=p[i]=0;
            q.push(i);
        }
    }
  
    while(!q.empty()){
        int now =q.front();
        q.pop();
        for(auto i:g[now]){
            int y = i.S;
            int x = i.F;
            if(!e[y]&&in[x]==0){
                e[y] = 1;
                int z = getid(s1[y]);
                int cost = c[now]+c[x]+cc[y];
                int pro = p[now]+p[x]+pp[y];
                //cout << cost <<' '<< pro << endl;
                if(cost<c[z]||cost==c[z]&&pro>p[z]){
                    c[z] = cost;
                    p[z] = pro;
                }
                if(--in[z]==0){
                    q.push(z);
                }
            }
        }
    }
    ll dp[10005];
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;

    f1(idx){
        for(int j= n ; j>=c[i];j--){
            if(~dp[j-c[i]]){
                if(dp[j]==-1){
                    dp[j]=dp[j-c[i]]+p[i];
                }
                else{
                    dp[j]=max(dp[j],dp[j-c[i]]+p[i]);
                }
            }
        }
    }
    ll val=0,cost=0;
    for(int i=1;i<=n;i++){
        if(dp[i]>val){
            val=dp[i];
            cost=i;
        }
    }
    cout << val << endl << cost << endl;
}
