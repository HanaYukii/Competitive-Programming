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
    int n;
    while(cin>>n){
        next:
        while(n--){
            int add,now;
            cin>>add;
            now=add;
            int cnt=0,cnt1=0;
            while(add){
                cnt++;
                if(add&1){
                    cnt1++;
                }
                add>>=1;
            }
            if(cnt1!=cnt){
                cout<<(1<<cnt)-1<<endl;
            }
            else{
                for(int i=2;i<=(int)sqrt(now);i++){
                    if(now%i==0){
                        cout<<now/i<<endl;
                        goto next;
                    }
                }
                cout<<1<<endl;
            }
        }
    }
}