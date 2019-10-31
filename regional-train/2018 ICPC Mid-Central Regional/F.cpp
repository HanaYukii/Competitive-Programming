#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
double dis(int x1,int y1,int x2,int y2){
    int sum = (x1-x2)*(x1-x2) + (y1-y2) * (y1-y2);
    return sqrt(sum);
}
int main(){
    int xx,yy;
    int x1,x2,y1,y2;
    cin >> xx >> yy >> x1 >> y1 >> x2 >> y2;
    double mi = 1e18;
    mi = min(mi,dis(xx,yy,x1,y1));
    mi = min(mi,dis(xx,yy,x1,y2));
    mi = min(mi,dis(xx,yy,x2,y1));
    mi = min(mi,dis(xx,yy,x2,y2));
    if(xx>=x1&&xx<=x2){
        mi = min(mi,(double)min(abs(yy-y1),abs(yy-y2)));
    }
    if(yy>=y1&&yy<=y2){
        mi = min(mi,(double)min(abs(xx-x1),abs(xx-x2)));
    }
    cout<<fixed<<setprecision(10)<<mi<<endl;
}
