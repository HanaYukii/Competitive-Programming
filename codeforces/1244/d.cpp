#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
vector<int>g[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while(cin >> n){
        ll c[n+5][3];
        ll ans[n+5];
        ll mi = 1e18;
        f(3){
            fr(j,1,n+1){
                cin >> c[j][i];
            }
        }
        f1(n)g[i].clear();
        f(n-1){
            int add1,add2;
            cin >> add1 >> add2;
            g[add1].pb(add2);
            g[add2].pb(add1);
        }
        f1(n){
            if(g[i].size()>=3){
                cout<<-1<<endl;
                exit(0);
            }
        }
        vector<int>t;
        vector<int>v;
        f1(n){
            if(g[i].size()==1){
                v.pb(i);
                v.pb(g[i][0]);
                for(int j=2;j<n;j++){
                    for(auto k:g[v.back()]){
                        if(k!=v[j-2]){
                            v.pb(k);
                            break;
                        }
                    }
                }
                break;
            }
        }
        t.pb(0);
        t.pb(1);
        t.pb(2);
        int tt = 30;
        while(tt--){
            random_shuffle(t.begin(),t.end());
            ll sum = 0;
            f(n){
                sum += c[v[i]][t[i%3]];
            }
            if(sum<mi){
                mi = sum;
                f(n){
                    ans[v[i]]=t[i%3]+1;
                }
            }
        }
        cout << mi << endl;
        f1(n){
            cout<<ans[i]<<' ';
        }
        cout << endl;
    }
}