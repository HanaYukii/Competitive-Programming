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
const int maxn=200005;
int cont[maxn];
int main(void){
	ios_base::sync_with_stdio(false);
	int n;
	while(cin>>n){
		string s1,s2;
		cin>>s1>>s2;
		set<int>s[4];
		f(n){
			if(s1[i]=='1'&&s2[i]=='1'){
				s[3].insert(i+1);
			}
			else if(s1[i]=='0'&&s2[i]=='1'){
				s[2].insert(i+1);
			}
			else if(s1[i]=='1'&&s2[i]=='0'){
				s[1].insert(i+1);
			}
			else{
				s[0].insert(i+1);
			}
		}
		for(int i=0;i<=s[1].size();i++){
			for(int j=0;j<=s[2].size();j++){
				int c1=i+j;
				int c2=s[1].size()+s[2].size()-i-j;
				int n1=i;
				int n2=s[2].size()-j;
				if(n1==n2){
					if((s[3].size()&1)==0){
						c1+=s[3].size()/2;
						c2+=s[3].size()/2;
						if(c1<=n/2&&c2<=n/2){
							//cout<<i<<' '<<j<<1<<endl;
							int num=0;
							for(auto k:s[1]){
								if(num<i){
									cout<<k<<' ';
									num++;
								}
								else{
									break;
								}
							}
							for(auto k:s[2]){
								if(num<i+j){
									cout<<k<<' ';
									num++;
								}
								else{
									break;
								}
							}
							for(auto k:s[3]){
								if(num<c1){
									cout<<k<<' ';
									num++;
								}
								else{
									break;
								}
							}
							for(auto k:s[0]){
								if(num<n/2){
									cout<<k<<' ';
									num++;
								}
								else{
									break;
								}
							}
							exit(0);
						}
					}
				}
				else if(n1<n2){
					if(s[3].size()>=n2-n1){
						if(((s[3].size()-(n2-n1))&1)==0){
							c1+=(s[3].size()-(n2-n1))/2;
							c2+=(s[3].size()-(n2-n1))/2;
							c1+=n2-n1;
							//cout<<i<<' '<<j<<2<<endl;
							if(c1<=n/2&&c2<=n/2){
								int num=0;
								for(auto k:s[1]){
									if(num<i){
										cout<<k<<' ';
										num++;
									}
									else{
										break;
									}
								}
								for(auto k:s[2]){
									if(num<i+j){
										cout<<k<<' ';
										num++;
									}
									else{
										break;
									}
								}
								for(auto k:s[3]){
									if(num<c1){
										cout<<k<<' ';
										num++;
									}
									else{
										break;
									}
								}
								for(auto k:s[0]){
									if(num<n/2){
										cout<<k<<' ';
										num++;
									}
									else{
										break;
									}
								}
								exit(0);
							}
						}
					}
				}
				else if(n1>n2){
					if(s[3].size()>=n1-n2){
						if(((s[3].size()-(n1-n2))&1)==0){
							c1+=(s[3].size()-(n1-n2))/2;
							c2+=(s[3].size()-(n1-n2))/2;
							c2+=n1-n2;
							if(c1<=n/2&&c2<=n/2){
								//cout<<i<<' '<<j<<3<<endl;
								int num=0;
								for(auto k:s[1]){
									if(num<i){
										cout<<k<<' ';
										num++;
									}
									else{
										break;
									}
								}
								for(auto k:s[2]){
									if(num<i+j){
										cout<<k<<' ';
										num++;
									}
									else{
										break;
									}
								}
								for(auto k:s[3]){
									if(num<c1){
										cout<<k<<' ';
										num++;
									}
									else{
										break;
									}
								}
								for(auto k:s[0]){
									if(num<n/2){
										cout<<k<<' ';
										num++;
									}
									else{
										break;
									}
								}
								exit(0);
							}
						}
					}
				}
			}
		}
		cout<<-1<<endl;
	}
}