#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));


int main(){
    ios_base::sync_with_stdio(0);
    int n;
    while(cin>>n){
        int Min=1e9;
        for(int i=1;i<=(int)sqrt(n);i++){
            Min=min(Min,i+(n-1)/i+1);
        }
        cout<<Min<<endl;
    }
    
}