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
int d[1000005];
int fi(int x){
    return d[x] == x ? x : d[x] = fi(d[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    f1(n){
        d[i] = i;
    }
    f(k){
        int add1, add2;
        cin >> add1 >> add2;
        int x = fi(add1);
        int y = fi(add2);
        d[x] = y;
    }
    int f = 0;
    f1(n){
        if(fi(i)!=fi(n+1-i)){
            f = 1;
        }
    }
    cout <<( f ? "No" : "Yes" )<< '\n';
}
