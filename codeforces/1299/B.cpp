#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 2000015
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const ll mod = 1e9+7;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int xx[n],yy[n];
    f(n){
        cin >> xx[i] >> yy[i];
    }
    if(n&1){
        cout<<"NO\n";
    }
    else{
        for(int i = 0 ; i < n/2 ; i++){
            int x1 = xx[i] - xx[i+1];
            int y1 = yy[i] - yy[i+1];
            int nxt = i + n/2;
            int x2 = xx[(nxt + 1)% n] - xx[nxt];
            int y2 = yy[(nxt + 1)% n] - yy[nxt];
            //cout << x1 <<' '<<x2<<' '<<y1<<' '<<y2<<endl;
            if(x1 != x2 || y1 != y2){
                cout<<"NO\n";
                exit(0);
            }
        }
        cout << "YES\n";
    }
}
