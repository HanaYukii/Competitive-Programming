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
using T = double;
const T EPS = 1e-8;
#define O operator
#define CP (const P &p) const 
typedef struct P { T x, y;
    P(T x = 0, T y = 0) : x(x), y(y) {}
    P O+CP { return P(x + p.x, y + p.y); }
    P O-CP { return P(x - p.x, y - p.y); }
    T O*CP { return x * p.x + y * p.y; }
    T O%CP { return x * p.y - y * p.x; }
    T O<CP { return (x < p.x) || ((x == p.x) && (y < p.y)); }
    P O*(const T c) const { return P(x * c, y * c); }
    P O/(const T c) const { return P(x / c, y / c); }
} V;
T leng2(V a) { return a * a; }
T leng(V a) { return sqrt(leng2(a)); }
T dist2(P a, P b) { return leng2(a - b); }
T dist(P a, P b) { return sqrt(dist2(a, b)); }
T cross(const P &o, const P &a, const P &b) {
      return (a - o) % (b - o);
}
vector<P> convexHull(vector<P> &ps) {
      sort(ps.begin(), ps.end());
        vector<P> stk, ret;
          for (auto &p : ps) {
                  while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) <= 0)
                            stk.pop_back();
                      stk.push_back(p);
                        }
            stk.pop_back();
              for (auto &p : stk) ret.push_back(p);
                reverse(ps.begin(), ps.end()); stk.clear();
                  for (auto &p : ps) {
                          while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) <= 0)
                                    stk.pop_back();
                              stk.push_back(p);
                                }
                    stk.pop_back();
                      for (auto &p : stk) ret.push_back(p);
                        return ret;
 }
          

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,r;
    cin >> n >> r;
    vector<P>v(n);
    f(n){

        cin >>v[i].x  >> v[i].y;
    }
    vector<P>vv = convexHull(v);
   // cout<<vv.size()<<endl;
    if(vv.size()<=2){
        cout<<"0.0000000"<<endl;
    }
    else{
        double ans = 2.0*r;
        int u = 1;
        int nn = vv.size();
        vv.pb(vv[0]);
        for(int i=0;i<nn;i++){
            while(cross(vv[i],vv[i+1],vv[u+1])-cross(vv[i],vv[i+1],vv[u])>=0)u=(u+1)%nn;
             double d = dist(vv[i],vv[i+1]);
             double h = 1.0 * fabs(cross(vv[i],vv[i+1],vv[u]))/d;
             //cout << d<<' '<< h << endl;
             ans = min(ans,h);
        }
        cout << fixed << setprecision(10)<<ans<<endl;
    }
}
