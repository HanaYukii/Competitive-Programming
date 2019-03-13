#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[5][5];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		f(3){
			fr(j,0,3){
				cont[i][j]=0;
			}
		}
		int turn=1,win=0;
		f(n){
			int add1,add2;
			cin>>add1>>add2;
			if(win)continue;
			if(cont[add1][add2])continue;
			cont[add1][add2]=turn+1;
			if(cont[0][0]==cont[0][1]&&cont[0][1]==cont[0][2]&&cont[0][2]){
				win=turn+1;
			}
			else if(cont[1][0]==cont[1][1]&&cont[1][1]==cont[1][2]&&cont[1][2]){
				win=turn+1;
			}
			else if(cont[2][0]==cont[2][1]&&cont[2][1]==cont[2][2]&&cont[2][2]){
				win=turn+1;
			}
			else if(cont[0][0]==cont[1][0]&&cont[1][0]==cont[2][0]&&cont[2][0]){
				win=turn+1;
			}
			else if(cont[0][1]==cont[1][1]&&cont[1][1]==cont[2][1]&&cont[2][1]){
				win=turn+1;
			}
			else if(cont[0][2]==cont[1][2]&&cont[1][2]==cont[2][2]&&cont[2][2]){
				win=turn+1;
			}
			else if(cont[0][0]==cont[1][1]&&cont[1][1]==cont[2][2]&&cont[2][2]){
				win=turn+1;
			}
			else if(cont[0][2]==cont[1][1]&&cont[1][1]==cont[2][0]&&cont[2][0]){
				win=turn+1;
			}
			turn^=1;
		}
		cout<<win-1<<endl;
	}
}