#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;

int cont[maxn];
int main(void){
	ios_base::sync_with_stdio(false);
	string s;
	while(cin>>s){
		int n0=0,n1=0;
		for(auto i:s){
			if(i=='0'){
				if(n0==0){
					cout<<1<<' '<<1<<endl;
				}
				else if(n0==1){
					cout<<1<<' '<<2<<endl;
				}
				else if(n0==2){
					cout<<1<<' '<<3<<endl;
				}
				else{
					cout<<1<<' '<<4<<endl;
				}
				n0++;
				n0%=4;
			}
			else{
				if(n1==0){
					cout<<3<<' '<<1<<endl;
				}
				else{
					cout<<3<<' '<<3<<endl;
				}
				n1^=1;
			}
		}
	}
}