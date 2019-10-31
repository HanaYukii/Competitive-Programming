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

int main(){
    int k;
    cin >> k;
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int sm = 0, dif = 0;
    f(n){
        if(s1[i]==s2[i]){
            sm++;
        }
        else{
            dif++;
        }
    }
    //if(sm<=k){
      //  cout<<n-(k-sm)<<endl;
    //}
    //else{
        cout<<n-abs(k-sm)<<endl;
    //}
}
