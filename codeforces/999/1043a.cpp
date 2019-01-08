#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 105
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;
int cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	int n;
	while(cin>>n){
			int Max=0;
			int sum1=0;
			for(int i=0;i<n;i++){
				cin>>cont[i];
				sum1+=cont[i];
				Max=max(Max,cont[i]);
			}
			while(1){
				int sum=0;
				for(int i=0;i<n;i++){
					sum+=Max-cont[i];
				}
				if(sum>sum1){
					cout<<Max<<endl;
					break;
				}
				else{
					Max++;
				}
			}
		}
	}	
