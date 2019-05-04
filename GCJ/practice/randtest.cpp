#include<bits/stdc++.h>
using namespace std;

int main(){
	srand(time(NULL));
	while(1){
		int cnt=0;
		int t=1000;
		int left=9;
		int b[9]={};
		while(t--){
			int k=rand()%9;
			if(!b[k]){
				b[k]=1;
				left--;
			}
			if(!left){
				left=9;
				memset(b,0,sizeof(b));
				cnt++;
			}
		}
		cout<<cnt*9<<endl;
		system("PAUSE");
	}

}