#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int n;
    while(cin>>n){
        string s;
        cin>>s;
        int c0=0,c8=0;
        for(auto i:s){
            if(i=='8'){
                c8++;
            }
            else{
                c0++;
            }
        }
        for(int i=1;i<=100;i++){
            if(c8<i||(n-i)/10<i){
                cout<<i-1<<endl;
                break;
            }
        }
    }
}