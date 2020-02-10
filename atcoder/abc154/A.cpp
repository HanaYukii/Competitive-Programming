#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    int a, b;
    cin >> s1 >> s2 >> a >> b;
    string ss;
    cin >> ss;
    if(ss==s1)a--;
    if(ss==s2)b--;
    cout << a <<' '<<b<<endl;
}
