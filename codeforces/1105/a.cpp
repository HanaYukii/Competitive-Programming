#include<bits/stdc++.h>
using namespace std;


int main(void){
	ios_base::sync_with_stdio(false);
	int n,x,y;
	while(cin>>n){
		int cont[1005];
		for(int i=0;i<n;i++){
			cin>>cont[i];
		}
		int Min=0;
		int Minv=1e9;
		for(int i=1;i<=100;i++){
			int now=0;
			for(int j=0;j<n;j++){
				if(cont[j]!=i)
					now+=min(abs(cont[j]-i-1),abs(cont[j]-i+1));
			}
			if(now<Minv){
				Minv=now;
				Min=i;
			}
		}
		cout<<Min<<' '<<Minv<<endl;
	}
}