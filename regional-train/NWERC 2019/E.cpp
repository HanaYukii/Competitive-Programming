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
#define double long double
const int mod = 1e9 + 7;
const double eps = 1e-9;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    vector<double>v;
    double tar;
    f(4){
        double add;
        cin >> add;
        v.pb(add);
    }
    cin >> tar;
    sort(v.begin(),v.end());
    tar *= 3;
    if(v[1]+v[2]+v[3] <= tar){
        cout << "infinite" << endl;
        exit(0);
    }
    else if(v[0]+v[1]+v[2] > tar){
        cout << "impossible" << endl;
        exit(0);
    }
    double l = 0 , r = 100;
    int t = 1000;
    while(t--){
        double m = (l + r) /2.0;
        vector<double>tmp = v;
        tmp.pb(m);
        sort(tmp.begin(),tmp.end());
        double sum = tmp[1] + tmp[2] + tmp[3];
        if(sum <= tar){
            l = m;
        }
        else{
            r = m;
        }
    }
    int ans = (int)(l * 100 + eps);
    cout << ans/100<<'.';
    ans %= 100;
    cout << ans/10;
    ans %= 10;
    cout << ans << endl;
}
