#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    while(cin >> n >> k){
        vector<ll>v;
        f(n){
            ll add;
            cin >> add;
            v.pb(add);
        }
        sort(v.begin(),v.end());
        int p1 = 0,p2 = n - 1;
        ll cnt = 1;
        ll dif = v.back()-v[0];
        while(1){
            ll nd = (v[p1+1]-v[p1])*cnt;
            if(nd>k){
                dif-=k/cnt;
                cout<<dif<<endl;
                exit(0);
            }
            k -= nd;
            dif -= v[p1+1]-v[p1];
            p1++;
            if(p1==p2){
                cout<<0<<endl;
                exit(0);
            }
            nd = (v[p2]-v[p2-1])*cnt;
            if(nd>k){
                dif-=k/cnt;
                cout<<dif<<endl;
                exit(0);
            }
            k -= nd;
            dif -= v[p2]-v[p2-1];
            p2--;
            if(p1==p2){
                cout<<0<<endl;
                exit(0);
            }
            cnt++;
        }
    }
}