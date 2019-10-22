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
    vector<int>v;
    v.pb(1);
    f(9){
        v.pb(v.back()*3);
    }
    set<int>st;
    f(1<<10){
        int sum = 0;
        for(int j=0;j<10;j++){
            if(i&(1<<j)){
                sum += v[j];
            }
        }
        st.insert(sum);
    }
    int t;
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        cout<<*st.lower_bound(num)<<'\n';
    }
}
