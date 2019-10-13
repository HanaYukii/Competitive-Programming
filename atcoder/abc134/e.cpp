#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=1e9+7;
 
int main(){
	int n;
	while(cin >> n){
		int cont[n+5] = {};
		f(n)cin >> cont[i];
		multiset<int>st;
		for(int i = n - 1 ; i >= 0 ; i-- ){
			if(st.upper_bound(cont[i])==st.end()){
				st.insert(cont[i]);
			}
			else{
				st.erase(st.upper_bound(cont[i]));
				st.insert(cont[i]);
			}
		}
		cout << st.size() << endl;
	}
 
}