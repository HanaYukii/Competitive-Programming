#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    int n;
    string s;
    cin>>n>>s;
    int now=0,pos=0,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            now++;
        }
        else{
            now--;
            cnt++;
        }
        if(now==-1){
            pos=i+1;
            break;
        }
    }
    if(pos){
        s[pos-1]='(';
        now=0;
        int f=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                now++;
            }
            else{
                now--;
            }
            if(now==-1){
                f=1;
                break;
            }
        }
        if(!now&&!f){
            cout<<cnt<<endl;
            exit(0);
        }
        s[pos-1]=')';
    }
    now=0;pos=0,cnt=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]==')'){
            now++;
        }
        else{
            now--;
            cnt++;
        }
        if(now==-1){
            pos=i+1;
            break;
        }
    }
    if(pos){
        s[pos-1]=')';
        now=0;
        int f=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                now++;
            }
            else{
                now--;
            }
            if(now==-1){
                f=1;
                break;
            }
        }
        if(!now&&!f){
            cout<<cnt<<endl;
            exit(0);
        }
    }
    cout<<0<<endl;
} 