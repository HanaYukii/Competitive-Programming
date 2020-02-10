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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int>nd;
    f1(n){
        int add;
        cin >> add;
        add %= (a + b);
        if(add == 0)add = a + b;
        nd.pb(max((add-1)/a,0));
    }
    sort(nd.begin(),nd.end());
    f(n){
        k -= nd[i];
        if(k < 0){
            cout << i <<endl;
            exit(0);
        }
    }
    cout << n << endl;
}
