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
	cin>>t;
	for(int c=1;c<=t;c++){
		string s;
		cin>>s;
		int n=s.size();
		int cont[n+5]={};
		f(n)cont[i]=s[i]-'0';
		int f=0;
		for(int i=1;i<n;i++){
			if(cont[i-1]>cont[i]){
				f=i;
				break;
			}
		}
		if(!f){
			printf("Case #%d: ",c);
			cout<<s<<endl;
		}
		else{
			printf("Case #%d: ",c);
			int first;
			for(int i=0;i<=f-1;i++){
				if(cont[i]==cont[f-1]){
					first=i;
					break;
				}
			}
			if(first==0&&cont[0]==1){
				f(n-1)cout<<9;
				cout<<endl;
			}
			else{
				f(first){
					cout<<cont[i];
				}
				cout<<cont[first]-1;
				f(n-1-first){
					cout<<9;
				}
				cout<<endl;
			}
		}
	}
}