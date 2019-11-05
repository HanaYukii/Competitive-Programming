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
    int n;
    cin >> n;
    int cnt[3]={};
    map<string,int>mp;
    f(n){
        string s;
        cin >> s;
        mp[s]++;
    }
    int ans = 0;
    f(n){
        string s;
        cin >> s;
        if(mp.count(s)&&mp[s]){
            ans++;
            mp[s]--;
        }
    }
    cout << ans << endl;    
}
