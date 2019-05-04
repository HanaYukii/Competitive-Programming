#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));

int main(){
	int t;
	cin >> t;
	for(int c = 1 ; c <=t;c++){
		string s;
		cin >> s;
		if(s.length()==1){
			if(s[0]=='5'){
				printf("Case #%d: 2 3\n",c);
			}
			else{
				printf("Case #%d: 1 %d\n",c,char(s[0]-'1'));
			}
			continue;
		}
		int sum = 0;
		for(int i=0;i<(int)s.length();i++){
			sum += s[i] - '0';
		}
		if(sum == 1){
			printf("Case #%d: 1 ",c);
			f((int)s.size()-1){
				cout<<9;
			}
			cout<<endl;
			continue;
		}
		int f = 0 ;
		string s1,s2;
		for(auto i:s){
			if(i != '1'){
				f = 1;
			}
			if(f){
				if(i=='5'){
					s1 +="2";
					s2 +="3";
				}
				else if(i=='0'){
					s1 +="0";
					s2 +="0";
				}
				else{
					s1 += "1";
					s2 += char(i-1);
				}
			}
			else{
				s1 += "1";
				s2 += "0";
				swap(s1,s2);
			}
			
		}
		printf("Case #%d: ",c );
		f = 0;
		for(auto i:s1){
			if(i!='0'){
				f=1;
			}
			if(f){
				cout<<i;
			}
		}
		cout << ' ';
		f = 0;
		for(auto i:s2){
			if(i!='0'){
				f=1;
			}
			if(f){
				cout<<i;
			}
		}
		cout<<endl;
	}
}