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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<pair<ll,ll> >st;
    int n;
    cin >> n;
    int ans = 0;
    int dx[] = {0,0,2018,-2018,1118,1118,-1118,-1118,1680,1680,-1680,-1680};
    int dy[] = {2018,-2018,0,0,1680,-1680,1680,-1680,1118,-1118,1118,-1118};
    f(n){
        ll add1, add2;
        cin >> add1 >> add2;
        fr(j,0,12){
            ll nx = add1 + dx[j];
            ll ny = add2 + dy[j];
            if(st.count({nx,ny}))ans++;
        }
        st.insert({add1,add2});
    }
    cout << ans << endl;
}
