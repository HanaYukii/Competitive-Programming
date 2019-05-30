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

int main()
{
	int t;
	cin >> t;
    for (int c = 1 ;c <= t;c++)
    {
    	vector<pair<int,int> >v;
    	vector<int>rem;
    	for(int i=1;i<=100;i++){
            int d;
            cin >> d;
            if(d==-1)exit(0);
            if(d<=72){
                cout<<d%12+9<<' '<<100<<endl;
            }
            else if(d<=80){
                cout<<d-72<<' '<<0<<endl;
                int add;
                cin >> add;
                v.pb({add,d-72});
                while(add--){
                    int tr;
                    cin >> tr;
                }
            }
            else if(d<=93){
                sort(v.begin(),v.end());
                cout<<v[(d-81)%5+3].second<<' '<<100<<endl;
                if(d==93){
                    for(int j=0;j<3;j++){
                        rem.pb(v[j].second);
                    }
                    v.clear();
                }
            }
            else if(d<=96){
                cout<<rem[d-94]<<' '<<0<<endl;
                int add;
                cin >> add;
                v.pb({add,rem[d-94]});
                sort(v.begin(),v.end());
                while(add--){
                    int tr;
                    cin >> tr;
                }
            }
            else if(d<=98){
                cout<<v[1].second<<' '<<100<<endl;
            }
            else if(d<=99){
                cout<<v[2].second<<' '<<100<<endl;
            }
            else{
                cout<<v[0].second<<' '<<100<<endl;
            }
    	}
    }
    return 0;
}
