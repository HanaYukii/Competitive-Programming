#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod =1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cur[n+5] = {};
    vector<int>v[n+5];
    f1(n){
        fr(j,0,n-1){
            int add;
            cin >> add;
            v[i].pb(add);
        }
    }
    int d = 1;
    while(1){
        int f = 0;
        vector<pair<int,int> >st;
        f1(n){
            if(cur[i]==n-1)continue;
            int nxt = v[i][cur[i]];
            int nnxt = v[nxt][cur[nxt]];
            if(nnxt == i&&nxt<nnxt){
                st.pb({nxt,nnxt});
            }
        }
        if(!st.size()){
            cout<<-1<<endl;
            exit(0);
        }
        for(auto i:st){
            cur[i.F]++;
            cur[i.S]++;
        }
        f1(n){
            if(cur[i]!=n-1){
                f = 1;
                break;
            }
        }
        if(!f){
            cout<<d<<endl;
            exit(0);
        }
        d++;
    }
}