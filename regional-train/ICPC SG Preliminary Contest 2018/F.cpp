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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    int sq = (int)sqrt(n);
    ll v[n+5] = {};
    ll del[sq][sq]={};
    while(q--){
        int op;
        cin >> op;
        if(op==2){
            int k;
            cin >> k;
            ll ans = v[k];
            fr(i,1,sq){
                ans += del[i][k%i];
            }
            cout << ans <<'\n';
        }
        else{
            int a,b,c;
            cin >> a >> b >> c;
            if(b<sq){
                del[b][a] += c;
            }
            else{
                for(int i = a; i <= n; i += b){
                    v[i] += c;
                }
            }
        }
    }
    
}
