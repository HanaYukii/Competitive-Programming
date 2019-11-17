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
    vector<pair<int,int> > v(n);
    for(auto &i:v){
        cin >> i.F >> i.S;
    }
    int rem[n+5] = {};
    f(n){
        rem[i] = 2;
    }
    int k;
    cin >> k;
    set<int>st;
    f(k){
        int add;
        cin >> add;
        st.insert(add);
        for(int j = 0 ; j < n ; j++){
            if(v[j].F <= add && v[j].S >= add){
                rem[j]--;
                if(rem[j] < 0){
                    cout << "impossible" << endl;
                    exit(0);
                }
            }
        }
    }
    vector<int>ans;
    for(int i = 0 ; i < n ; i++){
        if(!rem[i])continue;
        again:;
        if(rem[i+1]){
            if(st.count(v[i].S)){
                ans.pb(v[i].S-1);
            }
            else{
                ans.pb(v[i].S);
                if(i<n-1&&v[i].S == v[i+1].F){
                    rem[i+1]--;
                }
            }
        }
        else{
            if(st.count(v[i].F+1)){
                ans.pb(v[i].F+2);
            }
            else{
                ans.pb(v[i].F+1);
            }
        }
        st.insert(ans.back());
        rem[i]--;
        if(rem[i])goto again;
    }
    cout << ans.size() << endl;
    for(auto i:ans){
        cout << i <<' ';
    }
    cout << endl;
}
