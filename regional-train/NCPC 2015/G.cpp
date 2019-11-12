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
struct s{
    int tp;
    int x;
    double y;
};
bool cmp(s x,s y){
    if(x.y!=y.y){
        return x.y < y.y;
    }
    else{
        return x.tp > y.tp;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<s>v;
    int n;
    cin >> n;
    f(n){
        int x,y;
        cin >> x >> y;
        v.pb({0,x,y});
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int x,y,r;
        cin >> x >> y >> r;
        for(int j = 0 ; j <= r ; j++){
            double del = sqrt(r * r - j * j);
            v.pb({1,x-j,y-del});
            v.pb({1,x+j,y-del});
            v.pb({-1,x-j,y+del});
            v.pb({-1,x+j,y+del});
        }
    }
    sort(v.begin(),v.end(),cmp);
    int ans = n;
    map<int,int>mp;
    for(auto i:v){
        if(i.tp==0){
            if(mp[i.x]){
                ans--;
            }
        }
        else{
            mp[i.x] += i.tp;
        }
    }
    cout << ans << endl;
}
