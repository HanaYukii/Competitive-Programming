#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
const int mod=1e9+7;
int main(){
	int a,b,c,d;
    while(cin>>a>>b>>c>>d){
    	cout<<(b+d)*2+max(a,c)*2+4<<endl;
    }
}