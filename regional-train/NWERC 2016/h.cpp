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
ll g2b(string s){
    ll ret = 0;
    for(auto i:s){
        int now = i-'0';
        int l = ret&1;
        ret *= 2;
        ret += l^now;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    ll num1 = g2b(s1);
    ll num2 = g2b(s2);
    cout<<num2-num1-1<<endl;
}
