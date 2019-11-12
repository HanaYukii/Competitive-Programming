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
    string s;
    cin >> s;
    int n = s.size();
    s += "  ";
    map<char,char>mp;
    mp['R'] = 'S';
    mp['B'] = 'K';
    mp['L'] = 'H';
    f(n){
        string ss = s.substr(i,3);
        sort(ss.begin(),ss.end());
        if(ss=="BLR"){
            cout<<'C';
            i += 2;
        }
        else{
            cout<<mp[s[i]];
        }
    }
    cout << endl;
}
