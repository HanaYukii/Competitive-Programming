#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		string s1,s2;
		cin >> s1 >> s2;
		int sum[n+5]={};
		for(int i=0;i<n;i++){
			sum[i]=(s1[i]-'a')+(s2[i]-'a');
		}
		for(int i=n-1;i>0;i--){
			sum[i-1]+=sum[i]/26;
			sum[i]%=26;
		}
		int carry=0;
		for(int i=0;i<n;i++){
			cout<<char('a'+(sum[i]+carry*26)/2);
			if(sum[i]&1)carry=1;
			else carry=0;
		}
		cout<<endl;
	}


}