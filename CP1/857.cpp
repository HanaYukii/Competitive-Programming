#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int n,m,q;
    while(cin >> n >> q){
        ll pre[n+5] = {};
        f1(n){
            ll add;
            cin >> add;
            pre[i] = pre[i-1] ^ add;
        }
        while(q--){
            int l,r;
            cin >> l >> r;
            cout<<(pre[l-1]^pre[r])<<endl;
        }
    }
        
}