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
struct s{
    string name;
    int dep;
    int y,m,d;
    int id;
    bool operator < (const s &rhs)const{
        if(y != rhs.y){
            return y < rhs.y;
        }
        else if(m !=rhs.m){
            return m < rhs.m;
        }
        else if(d !=rhs.d){
            return d < rhs.d;
        }
        else if(dep != rhs.dep){
            return dep < rhs.dep;
        }
        else{
            return id < rhs.id;
        }
    }
};
set<s>w;
map<int,set<s>>mp;
map<int,map<int,s> >rmp;
map<int,int>id;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int tp;
        cin >> tp;
        if(tp == 1){
            int g;
            cin >> g;
            string name;
            cin >> name;
            int y,m,d;
            scanf("%d:%d:%d",&d,&m,&y);
            s add;
            add.name = name;
            add.dep = g;
            add.id = ++id[g];
            add.m = m;
            add.y = y;
            add.d = d;
            w.insert(add);
            mp[g].insert(add);
            rmp[g][add.id] = add;
            cout << (*w.begin()).name <<' '<<(*mp[g].begin()).name<<'\n';
        }
        else{
            int x,y;
            cin >> x >> y;
            s re = rmp[x][y];
            w.erase(re);
            mp[x].erase(re);
            if(w.size()){
                cout << (*w.begin()).name <<' ';
            }
            else{
                cout << "Vacant"<<' ';
            }
            if(mp[x].size()){
                cout << (*mp[x].begin()).name<<'\n';
            }
            else{
                cout << "Vacant" <<'\n';
            }
        }
    }
}
