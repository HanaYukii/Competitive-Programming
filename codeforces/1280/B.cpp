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
string s,real;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s[n+5];
        f(n){
            cin >> s[i];
        }
        int mi = 10;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(s[i][j]=='A'){
                    mi = min(mi,4);
                    if(i==0||i==n-1||j==0||j==m-1){
                        mi = 3;
                    }
                }
            }
        }
        if(s[0][0]=='A'||s[0][m-1] == 'A' || s[n-1][0] == 'A' || s[n-1][m-1] == 'A'){
            mi = 2;
        }
        for(int i = 0 ; i < n ; i++){
            int f = 0;
            for(int j = 0 ; j < m ; j++){
                if(s[i][j] != 'A'){
                    f = 1;
                }
            }
            if(!f){
                if(i==0||i==n-1){
                    mi = 1;
                }
                else{
                    mi = min(mi,2);
                }
            }
        }
        for(int j = 0 ; j < m ; j++){
            int f = 0;
            for(int i = 0 ; i < n ; i++){
                if(s[i][j] != 'A'){
                    f = 1;
                }
            }
            if(!f){
                if(j==0||j==m-1){
                    mi = 1;
                }
                else{
                    mi = min(mi,2);
                }
            }
        }
        int f = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(s[i][j] != 'A'){
                    f = 1;
                }
            }
        }
        if(!f){
            mi = 0;
        }
        if(mi == 10){
            cout << "MORTAL" << '\n';
        }
        else{
            cout << mi << '\n';
        }
    }
}
