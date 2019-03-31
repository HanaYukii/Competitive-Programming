#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	//while(cin >> n >> k){
		f(10){
			cout<<i<<endl;
			char s[100005];
			gets(s);
			//if(strstr(s,"no"))continue;
			if(strstr(s,"great")!=NULL){
				cout<<"normal"<<endl;
				exit(0);
			}
			else if(strstr(s,"so")!=NULL){
				cout<<"normal"<<endl;
				exit(0);
			}
			else if(strstr(s,"bad")!=NULL){
				cout<<"normal"<<endl;
				exit(0);
			}
			else if(strstr(s,"cool")!=NULL){
				cout<<"normal"<<endl;
				exit(0);
			}
			else if(strstr(s,"touch")!=NULL){
				cout<<"normal"<<endl;
				exit(0);
			}
			else if(strstr(s,"way")!=NULL){
				cout<<"grumpy"<<endl;
				exit(0);
			}
			if(strstr(s,"no"))continue;
			cout<<"grumpy"<<endl;
			exit(0);
		}
	//}
}