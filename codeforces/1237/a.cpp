#include<bits/stdc++.h>

#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
const int maxn = 200005;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while(cin >> n){
        int f = 0;
        vector<int>v;
        f(n){
            int num;
            cin >> num;
            if(num%2==0){
                v.pb(num/2);
            }
            else{
                int up = (abs(num)+1)/2;
                int down = up--;
                if(num<0){
                    up = -up;
                    down = -down;
                    swap(up,down);
                }
                if(f){
                    v.pb(up);
                }
                else{
                    v.pb(down);
                }
                f^=1;
            }
        }
        int sum = 0;
        for(auto i:v){
            cout<<i<<'\n';
            sum += i;
        }
        //cout << sum << endl;
    }
}