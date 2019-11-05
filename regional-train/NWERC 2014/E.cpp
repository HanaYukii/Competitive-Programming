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
double n,p,s,v;
double cal(double x){
    double num1 = n * pow(log2(n),x*sqrt(2))/1e9/p;
    double num2 = (1 + 1 / x) * s / v;
    return num1+num2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> s >> v;
    double lb = 0,rb = 1e18;
    int t = 1000;
    while(t--){
        double lm = (lb * 2 + rb) / 3;
        double rm = (rb * 2 + lb) / 3;
        if(cal(lm)>cal(rm)){
            lb = lm;
        }
        else{
            rb = rm;
        }
    }
    cout << fixed << setprecision(10) << cal(lb) << ' ' << lb << endl;
}
