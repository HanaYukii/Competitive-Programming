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
    int n, k;
    cin >> n >> k;
    vector<int>v;
    f(n){
        int add;
        cin >> add;
        v.pb(add);
    }
    int ans = 0;
    for(int i=0;i<v.size();i++){
        ans = max(ans,(int)(lower_bound(v.begin(),v.end(),v[i]+1000)-lower_bound(v.begin(),v.end(),v[i])));
    }
    cout << (ans-1)/k + 1 << endl;
}
