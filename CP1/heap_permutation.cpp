#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int cnt;
void heaps(int cont[],int n){
	if(n==1){
		/*for(int i=0;i<8;i++){
			cout<<cont[i]<<' ';
		}
		cout<<endl;*/
		cnt++;
		return;
	}
	f(n){
		heaps(cont,n-1);
		if(!(n&1)){
			swap(cont[i],cont[n-1]);
		}
		else{
			swap(cont[0],cont[n-1]);
		}
	}
	//heaps(cont,n-1);
}
int main(){
	double START,END;
    START = clock();
	int cont[12]={};
	f(12)cont[i]=i;
	heaps(cont,12);
	END=clock();
	cout<<END-START<<endl;
}