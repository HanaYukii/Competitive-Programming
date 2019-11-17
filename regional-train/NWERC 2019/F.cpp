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
const int mod = 1e9 + 7;
int d[maxn];
int fi(int x){
    return d[x] == x ? x : d[x] = fi(d[x]);
}
struct s{
    int x,y,v;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int,vector<int> >mp;
    f1(n){
        d[i] = i;
        int k;
        cin >> k;
        while(k--){
            int add;
            cin >> add;
            mp[add].pb(i);
        }
    }
    vector<s>ans;
    for(auto i:mp){
        vector<int>vv = i.S;
        int b = vv[0];
        for(int j = 1 ; j < vv.size() ;j++){
            int x = fi(b);
            int y = fi(vv[j]);
            if(x != y){
                d[x] = y;
                ans.pb({b,vv[j],i.F});
            }
        }
    }
    if(ans.size() != n - 1){
        cout << "impossible" << endl;
    }
    else{
        for(auto i:ans){
            cout << i.x <<' '<<i.y<<' '<<i.v<<'\n';
        }
    }
}
