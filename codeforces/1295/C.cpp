#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        vector<int>pos[26];
        for(int i = 0 ; i < s1.size() ; i++){
            pos[s1[i] - 'a'].pb(i);
        }
        int cur = 0, last = -1;
        int cnt = 1, f = 0;
        while(cur < s2.size()){
            int x = s2[cur] - 'a';
            if(!pos[x].size()){
                f = 1;
                break;
            }
            if(upper_bound(pos[x].begin(),pos[x].end(),last)==pos[x].end()){
                last = -1;
                cnt++;
                continue;
            }
            last = *upper_bound(pos[x].begin(),pos[x].end(),last);
            cur++;
        }
        if(f){
            cout << -1 << '\n';
        }
        else{
            cout << cnt << '\n';
        }
    }
}
