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
//#define int long long
const int mod = 1e9 + 7;
set<ll>st;
ll solve(ll n){
    if(n==1)return 0;
    if(st.count(n))return -1;
    st.insert(n);
    if(n&1){
        ll ret = solve((n+1)/2*3-1);
        if(ret == -1){
            return -1;
        }
        else{
            return ret + n + 1;
        }
    }
    else{
        ll ret = solve(n/2);
        if(ret == -1){
            return -1;
        }
        else{
            return ret + n;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << solve(n) << endl;
}
