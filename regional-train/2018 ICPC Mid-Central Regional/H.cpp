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
bool check(int num){
    set<int>st;
    int tmp = num;
    while(num){
        if(num%10==0)return 0;
        if(st.count(num%10))return 0;
        st.insert(num%10);
        num /= 10;
    }
    for(auto i:st){
        if(tmp%i)return 0;
    }
    return 1;
}
int main(){
    int l,r;
    cin >> l >> r;
    int ans = 0;
    for(int i=l;i<=r;i++){
        if(check(i)){
            ans++;
        }
    }
    cout << ans << endl;
}
