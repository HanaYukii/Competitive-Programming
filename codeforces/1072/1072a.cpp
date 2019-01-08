#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k;
	while(cin>>n>>m>>k){
		int sum=0,now=((n+m-2)<<1);
		while(k--){
			sum+=now;
			now-=16;
		}
		cout<<sum<<endl;
	}	
}