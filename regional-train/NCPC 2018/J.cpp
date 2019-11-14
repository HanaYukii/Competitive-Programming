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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll c0 = 1,c1 = 1;
    while(c0 * (c0-1)/2 < a){
        c0++;
    }
    while(c1 * (c1-1)/2 < d){
        c1++;
    }
   // cout << c0 <<' '<<c1<<endl;
    if(c0 * (c0-1) / 2 != a || c1 * (c1-1) / 2 != d){
        cout<<"impossible"<<endl;
        exit(0);
    }
    if(a==b&&b==c&c==d&&a==0){
        cout<<'1'<<endl;
        exit(0);
    }
    if(a==b&&b==c&&a==0){
        f(c1){
            cout<<1;
        }
        cout << endl;
        exit(0);
    }
    if(b==c&&c==d&&d==0){
        f(c0){
            cout<<0;
        }
        cout << endl;
        exit(0);
    }
    if(b + c != c0 * c1){
        cout << "impossible" << endl;
        exit(0);
    }
    int l1 = c1;
    int rem = b;
    f(c0+c1){
        if(rem >= l1){
            cout<<0;
            rem -= l1;
        }
        else{
            cout<<1;
            l1--;
        }
    }
    cout << endl;
}
