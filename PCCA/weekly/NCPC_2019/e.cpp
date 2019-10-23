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
    string s;
    getline(cin,s);
    int sp = 0;
    for(auto i:s){
        sp += (i==' ');
    }
    cin >> n;
    vector<string>name(n);
    vector<int>team;
    vector<pair<int,int> >o;
    f(n){
        cin >> name[i];
        team.push_back(0);
        o.push_back({0,i});
    }
    int k = 0;
    f(n){
        int f = 0;
        while(f<=sp){
            f += (team[k]==0);
            if(f==sp+1){
                team[k]=i%2+1;
                o[k].F=i;
            }
            k++;
            k%=n;
        }
    }
    sort(o.begin(),o.end());
    cout<<n/2+n%2<<endl;
    f(n){
        int c = o[i].S;
        if(team[c]==1){
            cout<<name[c]<<'\n';
        }
    }
    cout<<n/2<<endl;
    f(n){
        int c = o[i].S;
        if(team[c]==2){
            cout<<name[c]<<'\n';
        }
    }
    return 0;
}
