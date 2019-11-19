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
int dp[2][1000005];
bitset<105> pre[2][1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p,q;
    cin >> p;
    vector<int>v1,v2;
    v1.pb(0);v2.pb(0);
    f(n){
        int add;
        cin >> add;
        v1.pb(add);
    }
    cin >> q;
    f(n){
        int add;
        cin >> add;
        v2.pb(add);
    }
    int f = 0;
again:;
      f(2){
          fr(j,0,p){
              pre[i][j].reset();
              dp[i][j] = 0;
          }
      }
      f1(n){
         for(int j = 0 ; j < p ; j++){
            if(j >= v1[i] && dp[(i&1)^1][j-v1[i]] + v2[i] > dp[(i&1)^1][j]){
                dp[i&1][j] = dp[(i&1)^1][j-v1[i]] + v2[i];
                pre[i&1][j] = pre[(i&1)^1][j-v1[i]];
                pre[i&1][j].set(i);
                if(dp[i&1][j] >= q){
                    cout << "NO"<<endl;
                    fr(k,1,n+1){
                        cout<<pre[i&1][j][k];
                    }
                    cout << endl;
                    exit(0);
                }
            }
            else{
                dp[i&1][j] = dp[(i&1)^1][j];
                pre[i&1][j] = pre[(i&1)^1][j];
            }
         }
      }
      if(!f){
          f = 1;
          swap(v1,v2);
          swap(p,q);
          goto again;
      }
      cout << "YES" << endl;
}
