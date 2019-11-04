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
    int n,m,k;
    cin >> n >> m >> k;
    int sum = 0;
    vector<int>d;
    f(m){
        int add;
        cin >> add;
        d.pb(add);
        sum += add;
    }
    if(sum + (k - 1) * (m + 1) < n){
        cout << "NO"<<endl;
        exit(0);
    }
    cout << "YES"<<endl;
    int now = 0;
    int left = n-sum;
    int ans[n+5]={};
    for(int i=0;i<m;i++){
        now += min(left,k-1);
        left -= min(left,k-1);
        for(int j=now;j<now+d[i];j++){
            ans[j] = i + 1;
        }
        now = now + d[i];
    }
    f(n){
        cout << ans[i]<<' ';
    }
    cout << endl;
}
