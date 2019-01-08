#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	int l[maxn]={},r[maxn]={};
	int opc=0,lc=0,rc=0;
	int num[maxn]={};
	int op[maxn]={};
	while(t--){
		string s;
		int add;
		cin>>s>>add;
		if(s=="L"){
			opc++;
			lc++;
			l[opc]=lc;
			r[opc]=rc;
			num[add]=opc;
			op[opc]=1;
		}
		else if(s=="R"){
			opc++;
			rc++;
			l[opc]=lc;
			r[opc]=rc;
			num[add]=opc;
			op[opc]=2;
		}
		else{
			if(op[num[add]]==1){
				cout<<min(lc-l[num[add]],rc-r[num[add]]+num[add]-1)<<endl;
			}
			else{
				cout<<min(rc-r[num[add]],lc-l[num[add]]+num[add]-1)<<endl;
			}
		}
	}
}