#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	int t;
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		int n=(int)sqrt(k)+1;
		int b[100][3]={};
		int j=2;
		for(int i=2;1;i+=3){
			int left=9;
			while(1){
				cout<<i<<' '<<j<<endl;
				int add1,add2;
				cin>>add1>>add2;
				if(!add1)goto endd;
				if(add1==-1&&add2==-1)return 0;
				if(!b[add1][add2]){
					left--;
					b[add1][add2]=1;
				}
					
				if(!left)
					break;
			}
			
		}
		
		endd:;
	}
	return 0;
}