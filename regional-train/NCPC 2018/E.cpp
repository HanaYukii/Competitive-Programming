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
map<pair<vector<int>,vector<int> >,double>mp;
double solve(vector<int>v1,vector<int>v2,int k){
    if(mp.count({v1,v2})){
        return mp[{v1,v2}];
    }
    if(!v2.size())return 1;
    if(k==0){
        return 0;
    }
    int sz1 = v1.size();
    int sz2 = v2.size();
    double ret = 0;
    f(sz1){
        vector<int>tmp = v1;
        tmp[i]--;
        sort(tmp.rbegin(),tmp.rend());
        if(!tmp.back())tmp.pop_back();
        ret += 1.0/(sz1 + sz2) * solve(tmp,v2,k-1);
    }

    f(sz2){
        vector<int>tmp = v2;
        tmp[i]--;
        sort(tmp.rbegin(),tmp.rend());
        if(!tmp.back())tmp.pop_back();
        ret += 1.0/(sz1 + sz2) * solve(v1,tmp,k-1);
    }
    return mp[{v1,v2}] = ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>v1,v2;
    f(n){
        int add;
        cin >> add;
        v1.pb(add);
    }
    f(m){
        int add;
        cin >> add;
        v2.pb(add);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    cout << fixed << setprecision(10) << solve(v1,v2,k) << endl;
}
