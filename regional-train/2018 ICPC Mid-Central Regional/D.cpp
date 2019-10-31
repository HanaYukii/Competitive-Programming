#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;

int main(){
    map<char,int>mp;
    f(5){
        string s;
        cin >> s;
        mp[s[0]]++;
    }
    int mx = 0;
    for(auto i:mp){
        mx = max(mx,i.S);
    }
    cout << mx << endl;
}
