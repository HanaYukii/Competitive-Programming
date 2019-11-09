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
set<int>non;
set<int>g[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    f(m){
        int add1,add2;
        cin >> add1 >> add2;
        g[add1].insert(add2);
        g[add2].insert(add1);
    }
    f1(n){
        non.insert(i);
    }
    int cnt = -1;
    while(non.size()){
        cnt++;
        int nxt = *non.begin();
        non.erase(nxt);
        queue<int>q;
        q.push(nxt);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            set<int>era;
            for(auto i:non){
                if(!g[now].count(i)){
                    era.insert(i);
                }
            }
            for(auto i:era){
                q.push(i);
                non.erase(i);
            }
        }
    }
    cout << cnt << endl;
}
