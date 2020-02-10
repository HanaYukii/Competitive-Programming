#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
pair<int,int>solve(vector<int>v,int cur){
    vector<int>v1,v2;
    for(auto i:v){
        if(i&(1<<cur)){
            v1.pb(i);
        }
        else{
            v2.pb(i);
        }
    }
    if(!v2.size()){
        if(cur == 0){
            return {0,1};
        }
        pair<int,int>ret = solve(v1,cur-1);
        ret.S += (1<<cur);
        return ret;
    }
    else if(!v1.size()){
        if(cur == 0){
            return {0,0};
        }
        pair<int,int>ret = solve(v2,cur-1);
        return ret;
    }
    else{
        if(cur == 0){
            return {1,1};
        }
        pair<int,int>ret2 = solve(v2,cur-1);
        pair<int,int>ret1 = solve(v1,cur-1);
        if(ret1.F < ret2.F){
            ret1.F += (1<<cur);
            return ret1;
        }
        else{
            ret2.F += (1<<cur);
            ret2.S += (1<<cur);
            return ret2;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i:v){
        cin >> i;
    }
    cout << solve(v,29).F << '\n';
}
