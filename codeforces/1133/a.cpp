#include<bits/stdc++.h>
using namespace std;


int main(void){
	ios_base::sync_with_stdio(false);
	string s1,s2;
	while(cin>>s1>>s2){
		int h1,h2,m1,m2;
		h1=(s1[0]-'0')*10+s1[1]-'0';
		h2=(s2[0]-'0')*10+s2[1]-'0';
		m1=(s1[3]-'0')*10+s1[4]-'0';
		m2=(s2[3]-'0')*10+s2[4]-'0';
		int mt=(h1*60+h2*60+m1+m2)/2;
		printf("%02d:%02d\n",mt/60,mt%60);
	}
}