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
int solve(int x){
    int ret = 0;
    int cur = 1;
    int last = 0;
    int t = 8;
    while(t--){
        int now = (cur&(last^x));
        if(now){
            last = cur *2;
            ret += cur;
        }
        else{
            last = 0;
        }
        cur <<= 1;
    }
    return ret;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int add;
        cin >> add;
        cout << solve(add) <<' ';
    }
    cout << endl;
}
