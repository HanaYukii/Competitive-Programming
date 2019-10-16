#include<bits/stdc++.h>

#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
const int maxn = 200005;
multiset<int>st1;
map<int,multiset<int> >st2;
map<pair<int,int>,multiset<int> >st3;
struct s
{
    int x,y,z;
    bool operator <(const  s& rhs)const{
        if(x!=rhs.x){
            return x<rhs.x;
        }
        else if(y!=rhs.y){
            return y<rhs.y; 
        }
        else{
            return z<rhs.z;
        }
    }
};
map<s,int>mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while(cin >> n){
        vector<s>v;
        v.pb({0,0,0});
        f1(n){
            s add;
            cin >> add.x >> add.y >> add.z;
            mp[add] = i;
            st1.insert(add.x);
            st2[add.x].insert(add.y);
            st3[{add.x,add.y}].insert(add.z);
            v.pb(add);
        }
        int u[n+5] = {};
        //cout<<"here"<<endl;
        f1(n){
            if(u[i])continue;
            int nx = v[i].x;
            int ny = v[i].y;
            int nz = v[i].z;
            //cout<<nx<<' '<<ny<<' '<<nz<<endl;
            st1.erase(st1.lower_bound(nx));
            st2[nx].erase(st2[nx].lower_bound(ny));
            st3[{nx,ny}].erase(st3[{nx,ny}].lower_bound(nz));
            int tx,ty,tz;
            if(st1.lower_bound(nx)==st1.end()){
                tx = *(--st1.end());
            }
            else{
                tx = *(st1.lower_bound(nx));
            }
            if(st2[tx].lower_bound(ny)==st2[tx].end()){
                ty = *(--st2[tx].end());
            }
            else{
                ty = *(st2[tx].lower_bound(ny));
            }
            if(st3[{tx,ty}].lower_bound(nz)==st3[{tx,ty}].end()){
                tz = *(--st3[{tx,ty}].end());
            }
            else{
                tz = *(st3[{tx,ty}].lower_bound(nz));
            }
            st1.erase(st1.lower_bound(tx));
            st2[tx].erase(st2[tx].lower_bound(ty));
            st3[{tx,ty}].erase(st3[{tx,ty}].lower_bound(tz));
            s tar;
            tar.x=tx;
            tar.y=ty;
            tar.z=tz;
            int idx = mp[tar];
            cout<<i<<' '<<idx<<'\n';
            u[i] = u[idx] = 1;
            //cout<<tx<<' '<<ty<<' '<<tz<<endl;
        }
    }
}