#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
int n;
pair<int,int>a[maxn];
int ans[maxn];
void solve(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i*2-1].F >> a[i*2].F;
        a[i*2-1].S = -i;
        a[i*2].S = i;
        ans[i] = 0;
    }
    sort(a+1,a+2*n+1);
    set<int>s;
    int c = 0;
    for(int i = 1 ; i <= 2 * n ; i++){
        if(a[i].second < 0){
            s.insert(-a[i].second);
        }
        else{
            s.erase(a[i].second);
        }
        if(s.size() == 0){
            c++;
        }
        if(s.size() == 1 && a[i].second > 0 && a[i+1].second < 0 && a[i+1].first > a[i].first){
            ans[*s.begin()]++;
        }
        if(s.size() == 1 && a[i].second < 0 && a[i+1].second > 0){
            ans[*s.begin()]--;
        }
    }
    int d = -1;
    f1(n){
        d = max(d,ans[i]);
    }
    cout << c + d << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
