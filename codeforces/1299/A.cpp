#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 2000015
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const ll mod = 1e9+7;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int>v[32];
    vector<int>ans;
    for(int i = 0 ; i < n ; i++){
        int add;
        cin >> add;
        ans.pb(add);
        for(int j = 0; j < 31 ; j++){
            if(add&(1<<j)){
                v[j].pb(i);
            }
        }
    }
    int x = 0;
    for(int  i = 31 ; i >= 0 ; i--){
        if(v[i].size()==1){
            x = v[i][0];
            break;
        }
    }
    cout << ans[x] <<' ';
    for(int i = 0 ; i < n ; i++){
        if(i != x){
            cout << ans[i] <<' ';
        }
    }
    cout << endl;
}
