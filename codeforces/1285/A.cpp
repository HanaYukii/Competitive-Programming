#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
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
    int mi = 0, mx = 0;//, cur = 0;
    int n;
    string s;
    cin >> n >> s;
    for(auto i:s){
        if(i=='L'){
            mi--;
        }
        else{
            mx++;
        }
    }
    cout << mx - mi + 1 << '\n';
}
