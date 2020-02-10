#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
 vector<pair<pair<int,int>,pair<int,int> >v(maxn);

bool cmp(pair<pair<int,int>,pair<int,int> >x,pair<pair<int,int>,pair<int,int> >y){
    return x.F.S < y.F.S;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(auto &i:v){
        cin >> i.F.F >> i.F.S >> i.S.F >>i.S.S;
    }
    int t = 2;
    while(t--){
        sort(v.begin(),v.end(),cmp);
        vector<int>l,r;
        for(int i = 0 ; i< n ; i++){
            l.pb(data[i].S.F);
            r.pb(data[i].S.S);
        }
        for(int i = 1 ; i < n ; i++){
            int l = -1, r = i + 1;
            while(r - l > 1){
                int mid = (l + r) >> 1;
                if(v[mid].F.S < v[i].F.F){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            if(r != i){
                pair<int,int>ret = query(1,1,n,R,i);
                if(data[i].S.F > r || data[i].S.S < l){
                    cout << "NO\n";
                    exit(0);
                }
            }
        }
    }
}
