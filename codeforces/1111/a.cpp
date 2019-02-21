#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll cont[maxn];
bool isv(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return 1;
    else 
        return 0;
}
int main(){
    string s,t;
    cin>>s>>t;
    if(s.size()!=t.size()){
        cout<<"No"<<endl;
    }
    else{
        int n=s.size();
        f(n){
            if(isv(s[i])!=isv(t[i])){
                cout<<"No"<<endl;
                exit(0);
            }
        }
        cout<<"Yes"<<endl;
    }
}