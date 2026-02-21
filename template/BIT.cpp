// Binary Indexed Tree (Fenwick Tree)
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
int b[maxn];
int n;
int sum(int x){
    int ret = 0;
    while(x){
        ret += b[x];
        x -= (x) & (-x);
    }
    return ret;
}
void update(int x){
    while(x <= n){
        b[x]++;
        x += x & (-x);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
}
