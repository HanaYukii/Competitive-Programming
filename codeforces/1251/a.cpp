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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n=s.size();
        s = " "+s;
        int f[26]={};
        int cnt = 1;
        int cur = s[1]-'a';
        for(int i=2;i<=n;i++){
            if(s[i]-'a'==cur){
                cnt++;
            }
            else{
                if(cnt&1){
                    f[cur]=1;
                }
                cur = s[i]-'a';
                cnt = 1;
            }
        }
        if(cnt&1)f[cur]=1;
        f(26){
            if(f[i]){
                cout<<(char)('a'+i);
            }
        }
        cout << endl;
    }
}
