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
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int cnt[4] ={};
    f(n){
        int add1, add2;
        cin >> add1 >> add2;
        if(add1 > x){
            cnt[0]++;
        }
        if(add1 < x){
            cnt[1]++;
        }
        if(add2 > y){
            cnt[2]++;
        }
        if(add2 < y){
            cnt[3]++;
        }
    }
    int mx = 0;
    f(4){
    //    cout << cnt[i] << endl;
        if(cnt[i] > cnt[mx]){
            mx = i;
        }
    }
    cout << cnt[mx] << endl;
    if(mx == 0){
        cout << x + 1 <<' '<<y<<endl;
    }
    else if(mx == 1){
        cout << x - 1 <<' '<<y<<endl;
    }
    else if(mx == 2){
        cout << x <<' '<< y + 1 <<endl;
    }
    else{
        cout << x <<' ' << y - 1 <<endl;
    }
}
