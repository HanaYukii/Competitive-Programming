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
    int n,k;
    while(cin>>n>>k){
        int now=0;
        for(int i=0;i<k;i++){
            int add;
            cin>>add;
            if(i==k-1){
                if(add&1){
                    now^=1;
                }
            }
            else if((add&1)&&(n&1)){
                now^=1;
            }
        }
        if(now^1){
            cout<<"even"<<endl;
        }
        else{
            cout<<"odd"<<endl;
        }
    }
}