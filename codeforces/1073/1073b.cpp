#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;
int cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	int n;
	while(cin>>n){
		int now=0;
		int p[maxn];
		f1(n){
			int add;
			cin>>add;
			p[add]=i;
		}
		f1(n){
			int add;
			cin>>add;
			if(p[add]>now){
				cout<<p[add]-now<<' ';
				now=p[add];
			}
			else{
				cout<<0<<' ';
			}
		}
		cout<<endl;
	}	
}