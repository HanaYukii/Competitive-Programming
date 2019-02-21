#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
ll preo[200005];
ll pree[200005];
int main(){
	int n;
    while(cin>>n){
    	f1(n){
    		int add;
    		cin>>add;
    		if(i&1){
    			preo[i]=preo[i-1]+add;
    			pree[i]=pree[i-1];
    		}
    		else{
    			pree[i]=pree[i-1]+add;
    			preo[i]=preo[i-1];
    		}
    	}
    	int cnt=0;
    	f1(n){
    		if(pree[i-1]-pree[0]+preo[n]-preo[i]==preo[i-1]-preo[0]+pree[n]-pree[i]){
    			cnt++;
    		}
    	}
    	cout<<cnt<<endl;
    }
}