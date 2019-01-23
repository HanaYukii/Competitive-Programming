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
int vis[1005][1005];
struct pos{
	int x,y,p;
};
queue<pos>q[10];
int sp[10];
int main(void){
	ios_base::sync_with_stdio(false);
	string s;
	while(cin>>s){
		int n=s.size();
		int fb=-1,lb=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='['){
				if(fb==-1){
					fb=i;
				}
			}
			else if(s[i]==']'){
				lb=i;
			}
		}
		if(fb==-1||lb==-1||fb>lb){
			cout<<-1<<endl;
			exit(0);
		}
		int fs=-1,ls=-1;
		for(int i=fb+1;i<lb;i++){
			if(s[i]==':'){
				if(fs==-1){
					fs=i;
					ls=i;
				}
				else{
					ls=i;
				}
			}
		}
		if(fs==ls){
			cout<<-1<<endl;
			exit(0);
		}
		int cnt=0;
		for(int i=fs+1;i<ls;i++){
			if(s[i]=='|'){
				cnt++;
			}
		}
		cout<<cnt+4<<endl;
	}
}