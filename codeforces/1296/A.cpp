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
    int t;
    cin >> t;
    while(t--){
        int n;
        int ho = 0, he = 0;
        cin >> n;
        f(n){
            int add;
            cin >> add;
            if(add&1)ho = 1;
            else he = 1;
        }
        if(ho&&he){
            cout << "YES\n";
        }
        else if(n%2==1&&ho){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
