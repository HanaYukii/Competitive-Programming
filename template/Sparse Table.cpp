nclude<bits/stdc++.h>
using namespace std;

int n;
int g[100005][20];
int p2[20];
map<int,vector<int> >mp;
void init(){
    cin >> n;
    p2[0] = 1;
    for(int i = 1 ; i <= 19 ; i++){
        p2[i] = p2[i-1] * 2;
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> g[i][0];
        mp[g[i][0]].push_back(i);
    }
    for(int i = 1 ; i < 20 ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j-1+p2[i]>n){
                break;
            }
            g[j][i] = __gcd(g[j][i-1],g[j+p2[i-1]][i-1]);
        }
    }
}
int query(int l,int r){
    int ret = 0;
    int cnt = r - l + 1;
    int cur = 0;
    int pos = l;
    while(cnt){
        if(cnt&1){
            ret = __gcd(ret,g[pos][cur]);
            pos += p2[cur];
        }
        cur++;
        cnt >>= 1;
    }
    return ret;
}
void solve(){
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int g = query(l,r);
        int cnt = 0;
        if(mp.count(g)){
            cnt =  upper_bound(mp[g].begin(),mp[g].end(),r) - lower_bound(mp[g].begin(),mp[g].end(),l);
        }
        cout << r - l + 1 - cnt << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
}
