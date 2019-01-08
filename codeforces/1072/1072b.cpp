#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		n--;
		int f=0;
		int ans[100005]={};
		int cont[100005]={};
		int cont2[100005]={};
		for(int i=1;i<=n;i++){
			cin>>cont[i];
		}
		for(int i=1;i<=n;i++){
			cin>>cont2[i];
		}
		for(int i=0;i<4;i++){
			ans[0]=i;
			for(int j=1;j<=n;j++){
				int ff=0;
				for(int k=0;k<4;k++){
					if((k|ans[j-1])==cont[j]&&(k&ans[j-1])==cont2[j]){
						ff=1;
						ans[j]=k;
					}
					if(ff)break;
				}
				if(!ff){
					break;
				}
				if(j==n){
					f=1;
				}
			}
			if(f){
				break;
			}
		}
		if(!f){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(int i=0;i<=n;i++){
				cout<<ans[i]<<' ';
			}
			cout<<endl;
		}
	}	
}