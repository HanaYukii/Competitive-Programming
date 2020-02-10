#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p1 = 0, p2 = 0;
    string s;
    cin >> s;
    int ans[n+5] = {};
    for(int i = 0 ; i < s.size();i++){
        if(p1 < p2){
            if(s[i] - 'a' >= p2){
                ans[i] = 1;
                p2 = s[i] - 'a';
            }
            else if(s[i] - 'a' >= p1){
                ans[i] = 0;
                p1 = s[i] - 'a';
            }
            else{
                cout << "NO\n";
                exit(0);
            }
        }
        else{
            if(s[i] - 'a' >= p1){
                ans[i] = 1;
                p1 = s[i] - 'a';
            }
            else if(s[i] - 'a' >= p2){
                ans[i] = 0;
                p2 = s[i] - 'a';
            }
            else{
                cout << "NO\n";
                exit(0);
            }
        }
    }
    cout << "YES\n";
    f(n){
        cout << ans[i];
    }
    cout << '\n';
}
