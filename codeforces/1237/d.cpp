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
        int v[3*n+5];
        int mi = 1e9;
        int mx = 0;
        f(n){
            int add;
            cin >> add;
            v[i] = v[i+n] = v[i+2*n] = add;
            mi = min(mi,add);
            mx = max(mx,add);
        }
        if(mi*2>=mx){
            f(n){
                cout<<-1<<' ';
            }
            cout << endl;
            exit(0);
        }
        deque<pair<int,int> >q;
        int l = 0;
        int ans[n+5] = {};
        f(3*n){
            int tar = 2*v[i];
            if(q.size()&&q.front().F>tar){
                  pair<int,int>now;
                  while(q.size()&&q.front().F>tar){
                    now = q.front();
                    q.pop_front();
                  }
                  //cout<<i<<' '<<l<<' '<<now.S<<endl;
                for(int j=l;j<=now.S;j++){
                 ans[j] = i-j;
               }
               l = now.S + 1;
               if(l>=n)break;
            }
            while(q.size()&&q.back().F<v[i]){
                q.pop_back();
            }
            q.push_back({v[i],i});
        }
        f(n){
            cout<<ans[i]<<' ';
        }
        cout << endl;
    }
}