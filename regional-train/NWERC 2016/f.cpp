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
vector<int>v1,v2;
bool check(int x){
    vector<int>n1,n2;
    for(auto i:v1){
        if(i>x){
            n1.pb(i);
        }
    }
    for(auto i:v2){
        if(i>x){
            n2.pb(i);
        }
    }
    if((n1.size()&1)||(n2.size()&1)){
        return 0;
    }
    while(n1.size()){
        int now = n1.back();
        n1.pop_back();
        int now2 = n1.back();
        n1.pop_back();
        if(now!=now2)return 0;
    }
    while(n2.size()){
        int now = n2.back();
        n2.pop_back();
        int now2 = n2.back();
        n2.pop_back();
        if(now!=now2)return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    f(n){
        int add;
        cin >> add;
        v1.pb(add);
    }
    f(n){
        int add;
        cin >> add;
        v2.pb(add);
    }
    int mi = 0;
    for(int i=1<<30;i;i>>=1){
        int cur = (1<<30) - i - mi;
        if(cur<0)continue;
        if(check(cur)){
            mi += i;
        }
    }
    cout << (1<<30) - mi << endl;
}
