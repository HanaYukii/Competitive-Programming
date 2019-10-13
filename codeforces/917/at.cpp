#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    //while(cin >> n){
        string s;
        cin >> s;
        n = s.size();
        vector<int>l,r;
        f(n){
            if(s[i]=='L')l.pb(i);
            else r.pb(i);
        }
        int cnt[n+5] = {};
        f(n){
            if(s[i]=='L'){
                int idx = lower_bound(r.begin(),r.end(),i) - r.begin() - 1;
                if((i-r[idx])%2){
                    cnt[r[idx]+1]++;
                }
                else{
                    cnt[r[idx]]++;
                }
            }
            else{
                int num = *lower_bound(l.begin(),l.end(),i);
                if((num-i)%2){
                    cnt[num]++;
                }
                else{
                    cnt[num-1]++;
                }
            }
        }
        f(n){
            cout<<cnt[i]<<' ';
        }
        cout << endl;
    //}
}