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
        int f = 0;
        int c0 = 0,c1 = 0;
        int n;
        cin >> n;
        f(n){
            string s;
            cin >> s;
            int sz = s.size();
            if(sz&1){
                f = 1;
            }
            for(auto j:s){
                if(j=='0')c0++;
                else c1++;
            }
        }
        if(f==0&&c1%2==1){
            cout<<n-1<<'\n';
        }
        else{
            cout<<n<<'\n';
        }
    }
}
