#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ls(x) arr[x].child[0]
#define rs(x) arr[x].child[1]

int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin>>n>>m){
		if(m%n){
			cout<<-1<<endl;
		}
		else{
			m/=n;
			int cnt=0;
			while(m%2==0&&m){
				m/=2;
				cnt++;
			}
			while(m%3==0&&m){
				m/=3;
				cnt++;
			}
			if(m!=1){
				cout<<-1<<endl;
			}
			else{
				cout<<cnt<<endl;
			}
		}
	}
		
		
}