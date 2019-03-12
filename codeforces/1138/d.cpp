#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int maxn=1005;
int failure[500005];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s1,p;
	while(cin>>s1>>p){
		int c1=0,c2=0;
		ms(failure);
		for(auto i:s1){
			if(i=='0')c2++;
			else c1++;
		}
		for (int i=1, j=failure[0]=-1; i<(int)p.size(); ++i)
    	{
	        while (j >= 0 && p[j+1] != p[i])
	            j = failure[j];
	        if (p[j+1] == p[i]) j++;
	        failure[i] = j;
    	}
    	int f1=0,f2=0,g1=0,g2=0;
    	for(auto i:p){
    		if(i=='0')f2++;
			else f1++;
    	}
    	for(int i=failure[(int)p.size()-1]+1;i<p.size();i++){
    		if(p[i]=='0'){
    			g2++;
    		}
    		else{
    			g1++;
    		}
    	}
    	/*if(g1==0&&g2==0){
    		g1=f1;
    		g2=f2;
    	}*/
		if(c1>=f1&&c2>=f2){
			cout<<p;
			c1-=f1;
			c2-=f2;
			while(c1>=g1&&c2>=g2){
				cout<<p.substr(failure[(int)p.size()-1]+1,p.size()-failure[(int)p.size()-1]-1);
				c1-=g1;
				c2-=g2;
			}
		}
		f(c1){
			cout<<1;
		}
		f(c2){
			cout<<0;
		}
		cout<<endl;
	}
}