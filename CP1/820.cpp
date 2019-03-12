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


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(cin>>s){
		int16_t now[205]={};
		int cnt=0;
		for(auto i:s){
			if(i!='*'&&i!='+'){
				now[cnt++]=i-'0';
			}
			else{
				break;
			}
		}
		f(cnt/2){
			swap(now[i],now[cnt-1-i]);
		}
		int pos=cnt;
		int mx=cnt;
		while(pos<(int)s.size()){
			int op;
			if(s[pos]=='*'){
				op=1;
			}
			else {
				op=2;
			}
			//cout<<op<<endl;
			int16_t add[205];
			int cnt=0;
			pos++;
			while(pos<(int)s.size()){
				if(s[pos]=='*'||s[pos]=='+')break;
				add[cnt]=s[pos]-'0';
				cnt++,pos++;
			}
			f(cnt/2){
				swap(add[i],add[cnt-1-i]);
			}
			if(op==2){
				mx=max(mx,cnt);
				for(int i=0;i<cnt;i++){
					now[i]+=add[i];
				}
			}
			else{
				int16_t tmp[mx+cnt]={};
				for(int i=0;i<=mx;i++){
					for(int j=0;j<cnt;j++){
						if(now[i]&&add[j]){
							mx=max(mx,i+j);
							tmp[i+j]+=now[i]*add[j];
						}
					}
				}
				int f=0;
				for(int i=mx;i>=0;i--){
					if(tmp[i]&&f==0){
						f=i;
					}
					now[i]=tmp[i];
				}
				mx=f;
			}
			for(int i=0;i<=mx+4;i++){
				now[i+1]+=now[i]/10;
				now[i]%=10;
				if(now[i+1]){
					mx=max(mx,i+1);
				}
			}
		}
		int f=0;
		for(int i=200;i>=0;i--){
			if(now[i]){
				f=1;
			}
			if(f)cout<<now[i];
		}
		if(!f)cout<<0;
		cout<<'\n';
	}
}