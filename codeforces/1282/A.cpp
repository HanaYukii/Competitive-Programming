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
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > b){
            swap(a,b);
        }
        int mi;
        if(c + d <= a){
            mi = 0;
        }
        else if(c - d >= b){
            mi = 0;
        }
        else{
            mi = min(c+d,b) - max(c-d,a);
        }
        cout << b - a - mi << '\n';
    }
}
