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
    string s;
    cin >> s;
    int t;
    cin >> t;
    int pre[s.size() + 5][26] = {};
    s = " " + s;
    f1(s.size() - 1){
        fr(j,0,26){
            if(j == s[i] - 'a'){
                pre[i][j] = pre[i - 1][j] + 1;
            }
            else{
                pre[i][j] = pre[i - 1][j];
            }
        }
    }
    while(t--){
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        f(26){
            if(pre[r][i] - pre[l - 1][i]){
                cnt++;
            }
        }
        if(l == r){
            cout << "Yes\n";
        }
        else if(s[l] == s[r] && cnt <= 2){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
    }
}
