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
const ll mod =1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int>v[100005];
    f(n){
        int a,b;
        cin >> a >> b;
        v[a].pb(b);
    }
    multiset<int>st;
    int ans = 0;
    f1(m){
        for(auto j:v[i]){
            st.insert(j);
        }
        if(st.size()){
            ans += *(--st.end());
            st.erase(--st.end());
        }
    }
    cout << ans << endl;
}