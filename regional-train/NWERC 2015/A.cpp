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
    map<int,int>mp;
    int a,b;
    cin >> a >> b;
    vector<int>v1,v2;
    f(a){
       int add;
           cin >> add;
       v1.pb(add);
    }
     f(b){
        int add;
        cin >> add;
        v2.pb(add);
    }
    f(a){
        fr(j,0,b){
           if(v2[j]<v1[i])continue;
           mp[v2[j]-v1[i]]++;
        }
     }
     int ans = 0;
     for(auto i:mp){
        if(i.S>mp[ans]){
               ans = i.F;
        }
     }
     cout << ans << endl;
}
