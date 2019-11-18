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
    int n;
    cin >> n;
    multiset<int>st;
    f(1<<n){
        int add;
        cin >> add;
        st.insert(add);
    }
    vector<int>tar;
    st.erase(0);
    tar.pb(0);
    vector<int>ans;
    int t = n;
    while(t--){
        int now = *st.begin();
        ans.pb(now);
        vector<int>add;
        for(auto i:tar){
            int x = i + now;
            add.pb(x);
            st.erase(st.lower_bound(x));
        }
        for(auto i:add){
            tar.pb(i);
        }
    }
    for(auto i:ans){
        cout << (char)i;
    }
    cout << endl;
}
