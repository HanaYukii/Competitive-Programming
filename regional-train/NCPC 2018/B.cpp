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
int toint(string s){
    int ret = 0;
    for(auto i:s){
        ret *= 10;
        ret += i - '0';
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    f1(n){
        string s;
        cin >> s;
        if(s[0]=='m')continue;
        if(toint(s)!=i){
            cout << "something is fishy" << endl;
            exit(0);
        }
    }
    cout << "makes sense" << endl;
}
