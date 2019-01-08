#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll cont[1005];
int main(){
    int n;
    cin>>n;
    string s;
    int add=1;
    cin>>s;
    for(int i=0;i<n;i+=add){
        add++;
        cout<<s[i];
    }
    cout<<endl;
    
}