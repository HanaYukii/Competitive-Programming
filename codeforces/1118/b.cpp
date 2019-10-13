#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
ll preo[200005];
ll pree[200005];
int main(){
	int n;
    while(cin>>n){
    	int cont[n+5] = {};
        int sufo[n+5] = {};
        int sufe[n+5] = {};
        int preo[n+5] = {};
        int pree[n+5] = {};
        f1(n){
            cin >> cont[i];
        }
        preo[1] = cont[1];
        for(int i = 2 ; i <= n ; i++){
            if(i&1){
                preo[i] = preo[i-1] + cont[i];
                pree[i] = pree[i-1];
            }
            else{
                pree[i] = pree[i-1] + cont[i];
                preo[i] = preo[i-1];
            }
        }
        for(int i = n ; i >= 1 ; i--){
            if(i&1){
                sufo[i] = sufo[i+1] + cont[i];
                sufe[i] = sufe[i+1];
            }
            else{
                sufe[i] = sufe[i+1] + cont[i];
                sufo[i] = sufo[i+1];
            }
        }
        int ans = 0;
        f1(n){
            if(pree[i-1]+sufo[i+1]==preo[i-1]+sufe[i+1])ans++;
            //cout << pree[i-1] <<' '<<sufo[i+1]<<' '<<preo[i-1]<<' '<<sufe[i+1]<<endl;
        }
        cout << ans << endl;
    }
}