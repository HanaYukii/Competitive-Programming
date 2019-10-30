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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int>o,e;
        for(auto i:s){
            int cur = i-'0';
            if(cur&1){
                o.pb(cur);
            }
            else{
                e.pb(cur);
            }
        }
        int it1=0,it2=0;
        while(it1<o.size()&&it2<e.size()){
            if(o[it1]<e[it2]){
                cout<<o[it1++];
            }
            else{
                cout<<e[it2++];
            }
        }
        while(it1<o.size()){
            cout<<o[it1++];
        }
        while(it2<e.size()){
            cout<<e[it2++];
        }
        cout << endl;
    }
}
