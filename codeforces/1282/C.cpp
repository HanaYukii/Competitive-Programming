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
struct s{
    int t, dl;
};
bool cmp(s x, s y){
    return x.dl < y.dl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, t, a, b;
        cin >> n >> t >> a >> b;
        vector<s>v;
        int la = 0, lb = 0;
        int xx[n+5] = {};
        int yy[n+5] = {};
        f1(n){
            cin >> xx[i];
            if(xx[i] == 0){
                la++;
            }
            else{
                lb++;
            }
        }
        f1(n){
            cin >> yy[i];
        }
        f1(n){
            if(xx[i]==0){
                v.pb({a,yy[i]});
            }
            else{
                v.pb({b,yy[i]});
            }
        }
        sort(v.begin(),v.end(),cmp);
        int ans = 0;
        ll cur = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if(cur < v[i].dl){
                int cnt = i;
                int left = v[i].dl - cur - 1;
                int ua = min(la,left/a);
                left -= ua * a;
                int ub = min(lb,left/b);
                ans  = max(ans,cnt + ua + ub);
            }
            cur += v[i].t;
            if(v[i].t == b){
                lb--;
            }
            else{
                la--;
            }
        }
        if(cur <= t){
            ans = n;
        }
        cout << ans << '\n';
    }
}
