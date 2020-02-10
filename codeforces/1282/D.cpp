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
int inter(string s){
    cout << s << endl;
    int ret;
    cin >> ret;
    if(ret == 0){
        exit(0);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int last = 1e5;
    for(int i = 1 ; i <= 300 ; i++){
        s += "a";
        int x = inter(s);
        if(x >= last){
            break;
        }
    }
    int bcnt = last;
    s = "";
    for(int i = 0 ; i < bcnt ; i++){
        s += "b";
    }
    int acnt = inter(s);
    vector<int>ac(bcnt+1,0);
    int left = acnt;
    for(int i = 0 ; i <= bcnt ; i++){
        string now = "";
        ac[i] = left;
        for(int j = 0 ; j < bcnt ; j++){
            now += string(ac[j],'a');
            now += 'b';
        }
        int x = inter(now);
        ac[i] = left - x/2;
        left -= ac[i];
    }
    ac[bcnt] = left;
    string ans = "";
    for(int  i = 0 ; i < bcnt ; i++){
        ans += string(ac[i],'a');
        ans += 'b';
    }
    ans += string(left,'a');
    inter(ans);

}
