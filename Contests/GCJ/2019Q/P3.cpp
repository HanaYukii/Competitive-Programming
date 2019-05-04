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

		int n,k;
		cin >> k >> n;
		n++;
		int cont[n+5];
		int num[n+5];
		f(n-1){
			cin >>cont[i];
		}
		for(int i=0;i<n;i++){
			if(cont[i]!=cont[i+1]){
				num[i+1]=__gcd(cont[i],cont[i+1]);
				//cout<<num[i+1]<<endl;
				for(int j=i;j>=0;j--){
					num[j]=cont[j]/num[j+1];
					//cout<<num[j]<<endl;
				}
				for(int j=i+2;j<n;j++){
					num[j]=cont[j-1]/num[j-1];
					//cout<<num[j]<<endl;
				}
				break;
			}
			
		}
		set<int>st;
		f(n){
			st.insert(num[i]);
		}
		map<int,char>mp;
		char now='A';
		for(auto i:st){
			mp[i]=now;
			now++;
		}
		printf("Case #%d: ",c);
		for(int i=0;i<n;i++){
			cout<<mp[num[i]];
		}
		cout<<endl;
	}
}