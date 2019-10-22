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
        int n;
        cin >> n;
        vector<int>v;
        f(n){
            int add;
            cin >> add;
            v.pb(add);
        }
        sort(v.begin(),v.end());
        int f = 0;
        for(int i=1;i<v.size();i++){
            if(v[i-1]+1==v[i]){
                f = 1;
            }
        }
        if(f){
            cout<<2<<'\n';
        }
        else{
            cout<<1<<'\n';
        }
    }
}
