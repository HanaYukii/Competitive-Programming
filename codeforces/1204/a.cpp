#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int main(){
	string s;
    while(cin>>s){
    	if(s=="0"){
    		cout<<0<<endl;
    	}
    	else{
    		if(s.size()%2==0){
    			cout<<(s.size()+1)/2<<endl;
    		}
    		else{
    			int ans = (s.size()+1)/2;
    			int f = 0;
    			for(int i=1;i<s.size();i++){
    				if(s[i]=='1'){
    					f = 1;
    				}
    			}
    			if(!f){
    				ans--;
    			}
    			cout << ans << endl;
    		}
    	}
    }
}