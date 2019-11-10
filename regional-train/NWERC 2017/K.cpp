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
vector<int>gap;
vector<pair<double,double> >solve(vector<double>v,int l,int r){
    if(v.size() == 1){
        vector<pair<double,double> >ret;
        ret.pb({v[0],1});
        return ret;
    }
    int sep = 1;
    vector<double>v1,v2;

    for(int i=0;i<v.size();i++){
        if(i<max(gap[(l+r)/2]-gap[l],1)){
            v1.pb(v[i]);
        }
        else{
            v2.pb(v[i]);
        }
    }

    vector<pair<double,double> >ret1 = solve(v1,l,(l+r)/2);
    vector<pair<double,double> >ret2 = solve(v2,(l+r)/2,r);
    vector<pair<double,double> >ret;
    for(auto i:ret1){
        double sum = 0;
        for(auto j:ret2){
            sum += i.F / (i.F+j.F) * j.S;
        }
        sum *= i.S;
        ret.pb({i.F,sum});
    }
    for(auto i:ret2){
        double sum = 0;
        for(auto j:ret1){
            sum += i.F / (i.F+j.F) * j.S;
        }
        sum *= i.S;
        ret.pb({i.F,sum});
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    double o;
    cin >> o;
    vector<double>v;
    f(n-1){
        double add;
        cin >> add;
        v.pb(add);
    }
    sort(v.begin(),v.end());
    int p = 1;
    while((p<<1)<=n){
        p <<= 1;
    }
    double cur = v[0];
    vector<double>v1;
    v1.pb(o);
    for(int i=0;i<v.size();i++){
        v1.pb(v[i]);
    }
    gap.pb(0);
    p = n - (n - p) * 2;
    for(int i=0;i<p;i++){
        gap.pb(gap.back()+1);
    }
    while(gap.back()!=n){
        gap.pb(gap.back()+2);
    }

   // sleep(10000);
    //cout << v1.size() << ' ' << v2.size() << endl;
    vector<pair<double,double> >ans = solve(v1,0,gap.size()-1);
    cout << fixed << setprecision(10) << ans[0].S << endl;
}
