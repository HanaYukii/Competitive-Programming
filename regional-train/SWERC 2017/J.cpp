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
    int n;
    ll a[3]={};
    ll b[3]={};
    cin >> n;
    f1(n){
        ll add;
        cin >> add;
        a[i%3] += add;
    }
    f1(n){
        ll add;
        cin >> add;
        b[i%3]+= add;
    }
    ll ans[3]={};
    f(3){
        fr(j,0,3){
            ans[(i+j)%3]+=a[i]*b[j];
        }
    }
    f(3){
        cout<<ans[i]<<' ';
    }
    cout << endl;
}
