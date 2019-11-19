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
int n;
bool check(int x,int y){
    ll sum = 0;
    ll cur = x;
    while(sum < n){
        //cout <<x <<' '<<y<<endl;
        sum += cur;
        cur *= y;
    }
    return sum == n;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int ans = 0;
    f1(n){
        if(n%i)continue;
        fr(j,1,n/i){
            if(check(i,j)){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
