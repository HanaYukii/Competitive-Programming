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
    int n, m;
    cin >> n >> m;
    int ans[n+5][m+5];
    if(n==1&&m==1){
        cout << 0<<endl;
        exit(0);
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(n < m){
                ans[i][j] = i * (n + j);
            }
            else{
                ans[i][j] = j * (m + i);
            }
        }
    }
    f1(n){
        fr(j,1,m+1){
            cout << ans[i][j] <<' ';
        }
        cout << endl;
    }
}
