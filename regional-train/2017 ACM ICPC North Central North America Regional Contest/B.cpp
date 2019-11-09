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
vector<pair<int,int> >g[25];
map<string,int>mp;
int getid(string s){
    if(mp.count(s)){
        return mp[s];
    }
    else{
        int sz = mp.size();
        mp[s] = sz;
        return sz;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> >v;
    string s[n];
    f(n){
        int add1, add2;
        cin >> add1 >> add2 >> s[i];
        getid(s[i]);
        v.pb({add1,add2});
    }
    set<pair<int,pair<int,int> > >st;
    int dis[1<<n][n];
    f(n){
        fr(j,0,n){
            if(i==j)continue;
            g[i].pb({j,abs(v[i].F-v[j].F) + abs(v[i].S -v[j].S)});
        }
    }
    int sz = mp.size();
    f(1<<sz){
        fr(j,0,n){
            dis[i][j] = 1e9;
        }
    }
    f(n){
        int idx = mp[s[i]];
        int d = abs(v[i].F)+abs(v[i].S);
        dis[1<<idx][i] = d;
        st.insert({d,{1<<idx,idx}});
    }
    while(st.size()){
        pair<int,pair<int,int> >now = *st.begin();
        st.erase(now);
        int mask = now.S.F;
        int pos = now.S.S;
       // cout<<mask<<' '<<pos<<' '<<now.F<<endl;
        for(auto i:g[pos]){
            if(mask&(1<<getid(s[i.F])))continue;
            int d = now.F + i.S;
            int nxt = mask | (1<<getid(s[i.F]));
            if(dis[nxt][i.F]>d){
                st.erase({dis[nxt][i.F],{nxt,i.F}});
                dis[nxt][i.F] = d;
                st.insert({dis[nxt][i.F],{nxt,i.F}});
            }
        }
    }
    int mi =1e9;
    f(n){
        mi = min(mi,dis[(1<<sz)-1][i]+abs(v[i].F) + abs(v[i].S));
    }
    cout << mi << endl;

}
