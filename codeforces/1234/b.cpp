#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7;
 
int main(){
    int n,k;
    cin >> n >> k;
    set<pair<int,int> >st;
    map<int,int>last;
    for(int i=n;i>=1;i--){
        int add;
        cin >> add;
        if(st.count({last[add],add}))continue;
        if((int)st.size()==k){
            st.erase(--st.end());
        }
        last[add] = i;
        st.insert({last[add],add});
    } 
    cout<<st.size()<<endl;
    for(auto i:st){
        cout<<i.S<<' ';
    }
    cout << endl;
 
}