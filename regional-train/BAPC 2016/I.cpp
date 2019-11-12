#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n==1){
        cout << "no" << endl;
        exit(0);
    }
    int sq = sqrt(n);
    for(int i = 2 ; i <= sq ; i++){
        if(n % i)continue;
        while(n % i == 0){
            n /= i;
        }
        if(n != 1){
            cout << "no" << endl;
            exit(0);
        }
        else{
            cout << "yes" << endl;
            exit(0);
        }
    }
    cout << "yes" << endl;
}
