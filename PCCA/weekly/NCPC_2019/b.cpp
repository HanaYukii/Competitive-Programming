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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        vector<vector<ll> >v;
        f(3){
            vector<ll>add(2);
            cin >> add[0] >> add[1];
            v.pb(add);
        }
        int sp=100;
        ll mi = 9e18;
        while(sp--){
            f(3){
                random_shuffle(v[i].begin(),v[i].end());
            }
            random_shuffle(v.begin(),v.end());
            ll w = max({v[0][0],v[1][0],v[2][0]});
            ll h = v[0][1]+v[1][1]+v[2][1];
            mi = min(mi,w*h);
            if(v[0][0]<v[1][0]){
                swap(v[0][0],v[1][0]);
                swap(v[0][1],v[1][1]);
            }
            w = max(v[0][1]+v[1][1],v[2][1]);
            if(v[1][1]>=v[2][1]){
                h = max(v[0][0],v[2][0]+v[1][0]);
            }
            else{
                h = v[2][0]+v[0][0];
            }
            mi = min(mi,h*w);
        }
        cout << mi << endl;
    }
}
