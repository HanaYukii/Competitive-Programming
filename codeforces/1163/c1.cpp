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
#define bg begin()
#define ed end()
#define pii pair<int,int>
map<pair<int,int>,set<double>>mp;
set<int>ver;
struct Point
{
	int x,y;
};
const double eps=1e-5;
int main(){
	int n,m;
	while(cin >> n ){
		Point p[1005];
		f(n){
			cin >> p[i].x >> p[i].y;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int dx=p[j].x-p[i].x;
				int dy=p[j].y-p[i].y;
				if(dx==0){
					ver.insert(p[j].x);
					continue;
				}
				else if(dx<0){
					dx=-dx;
					dy=-dy;
				}
				int gcd=__gcd(dx,dy);
				dx/=gcd;
				dy/=gcd;
				double the=p[j].y-((double)p[j].x*(double)dy/(double)dx);
				mp[{dx,dy}].insert(the);
			}
		}
		ll sum=0;
		ll mi = 0;
		for(auto i:mp){
			ll sz=0;
			double pre=-1e18;
			for(auto j:i.second){
				if(j-pre<eps){
					continue;
				}
				pre=j;
				sz++;
			}
			sum += sz;
			mi += sz*(sz-1)/2;
		}
		sum += ver.size();
		mi += ver.size()*(ver.size()-1)/2;
		sum=sum*(sum-1)/2;
		sum-=mi;
		cout<<sum<<endl;
	}
}