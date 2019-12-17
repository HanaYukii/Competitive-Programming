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
ll sum[maxn];
int fi(int x){
    return d[x] == x ? x : d[x] = fi(d[x]);
}
bool cmp(int x,int y){
    return sum[x] < sum[y];
}
struct ans{
    ll x,y,z;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    f1(n){
        d[i] = i;
    }
    f(m){
        int add1, add2;
        ll add3;
        cin >> add1 >> add2 >> add3;
        sum[add1] += add3;
        sum[add2] -= add3;
        int x = fi(add1);
        int y = fi(add2);
        d[x] = y;
    }
    map<int,vector<int> >mp;
    f1(n){
        mp[fi(i)].pb(i);
    }
    vector<ans>a;
    for(auto i:mp){
        vector<int>tmp = i.S;
        sort(tmp.begin(),tmp.end(),cmp);
        int l = 0, r = tmp.size() - 1;
        while(l < r){
            if(sum[tmp[l]] == 0)break;
            ll mi = min(-sum[tmp[l]],sum[tmp[r]]);
            a.pb({tmp[l],tmp[r],mi});
            sum[tmp[l]] += mi;
            sum[tmp[r]] -= mi;
            if(sum[tmp[l]] == 0){
                l++;
            }
            if(sum[tmp[r]] == 0){
                r--;
            }
            //cout <<l <<' '<<r<<' '<<sum[tmp[l]]<<' '<<sum[tmp[r]]<<endl;
        }
    }
    cout << a.size() << '\n';
    for(auto i:a){
        cout << i.y <<' '<<i.x<<' '<<i.z<<'\n';
    }
}
