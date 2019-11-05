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
int tar;
int n;
vector<pair<ll,ll> >v;
bool check(){
    random_shuffle(v.begin(),v.end());
    int cur = 2;
    for(int i=2;i<v.size();i++){
        ll dx1 = v[i].F-v[0].F;
        ll dx2 = v[i].F-v[1].F;
        ll dy1 = v[i].S-v[0].S;
        ll dy2 = v[i].S-v[1].S;
        if(dx1 * dy2 == dx2 * dy1){
            cur++;
        }
    }
    return cur >= tar;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p;
    cin >> n >> p;
    f(n){
        int add1,add2;
        cin >> add1 >> add2;
        v.pb({add1,add2});
    }
    tar = n * p / 100;
    if(n * p % 100){
        tar++;
    }
    int t = 250;
    int f = 0;
    while(t--){
        f |= check();
        if(f)break;
    }
    if(f){
        cout<<"possible"<<endl;
    }
    else{
        cout<<"impossible"<<endl;
    }
}
