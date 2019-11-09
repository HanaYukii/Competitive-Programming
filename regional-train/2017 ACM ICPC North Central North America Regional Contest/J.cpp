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
    int x,y;
    int d;
};
bool cmp(s x,s y){
    return x.d < y.d;
}
int d[5005];
int fi(int x){
    return d[x] == x ? x : d[x] = fi(d[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<s>v;
    f1(n){
        fr(j,1,n+1){
            int add;
            cin >> add;
            v.pb({i,j,add});
        }
    }
    sort(v.begin(),v.end(),cmp);
    vector<pair<int,int> >ans;
    f1(n){
        d[i] = i;
    }
    for(auto i:v){
        int x = fi(i.x);
        int y = fi(i.y);
        if(x!=y){
            ans.pb({i.x,i.y});
            d[x] = y;
        }
    }
    for(auto i:ans){
        cout << i.F << ' ' << i.S << endl;
    }
}


