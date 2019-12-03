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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    vector<pair<ll,ll> >v;
    vector<int>o;
    int n;
    cin >> n;
    f(n){
        o.pb(i);
        ll add1,add2;
        cin >> add1 >> add2;
        v.pb({add1,add2});
    }
    double sum = 0;
    int cnt = 0;
    do{
        cnt++;
        for(int i = 1 ; i < n ; i ++){
            ll dx = v[o[i]].F - v[o[i-1]].F;
            ll dy = v[o[i]].S - v[o[i-1]].S;
            sum += sqrt(dx*dx+dy*dy);
        }
    }while(next_permutation(o.begin(),o.end()));
    cout << fixed << setprecision(10) << sum / cnt << endl;
}
