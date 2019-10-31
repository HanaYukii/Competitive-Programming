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
int d[1005];
int fi(int x){
    return d[x] == x ? x : d[x] = fi(d[x]);
}
struct e{
    int x,y;
    double dis;
};
bool cmp(e x,e y){
    return x.dis < y.dis;
}
vector<pair<double,double> >p;
vector<e>v;
int main(){
	int n,m,k;
    cin >> n >> m >> k;
    f(n){
        double add1,add2;
        cin >> add1 >> add2;
        p.pb({add1,add2});
    }
    f(n){
        if(i<m){
            d[i] = 0;
        }
        else{
            d[i] = i;
        }
    }
    f(n){
        fr(j,i+1,n){
            double dis = sqrt((p[i].F-p[j].F)*(p[i].F-p[j].F)+(p[i].S-p[j].S)*(p[i].S-p[j].S));
            v.pb({i,j,dis});
        }
    }
    sort(v.begin(),v.end(),cmp);
    f(k){
        int add1,add2;
        cin >> add1 >> add2;
        add1--,add2--;
        int x = fi(add1);
        int y = fi(add2);
        d[x] = y;
    }
    double ans = 0;
    for(auto i:v){
        int x = fi(i.x);
        int y = fi(i.y);
        if(x!=y){
            d[x] = y;
            ans += i.dis;
        }
    }
    cout << ans << endl;
}
