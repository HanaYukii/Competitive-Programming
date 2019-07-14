#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const double eps = 1e-6;
int main(){
	ll n;
	while(cin >> n){
		double dif = 0;
		vector<double>v;
		f(n){
			double add;
			cin >> add;
			v.pb(add);
			if(add>0){
				dif += add - floor(add+eps);
			}
			else if(add<0){
				dif -= ceil(add-eps) - add;
			}
		}	
		//cout<<dif<<endl;
		int m=0,p=0;
		if(dif>0){
			for(double i=0.5;i<dif;i+=1.0){
				p++;
			}
		}
		if(dif<0){
			for(double i=-0.5;i>dif;i-=1.0){
				m++;
			}
		}
		for(auto i:v){
			if(i>0){
				int fl = floor(i+eps);
				if(p&&i-fl>=eps){
					cout<<fl+1<<'\n';
					p--;
				}
				else{
					cout<<fl<<'\n';
				}
			}
			else{
				int fl = ceil(i-eps);
				if(m&&fl-i>=eps){
					cout<<fl-1<<'\n';
					m--;
				}
				else{
					cout<<fl<<'\n';
				}
			}
		}
	}
}