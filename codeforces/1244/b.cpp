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
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        int ans = n;
        string s;
        cin >> s;
        f(n){
            if(s[i]=='1'){
                ans = max(ans,max(i*2+2,n*2-i*2));
            }
        }
        cout << ans << '\n';
    }
}