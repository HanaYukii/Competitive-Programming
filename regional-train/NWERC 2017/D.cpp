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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string>v;
    int n;
    cin >> n;
    f(n){
        string s;
        cin >> s;
        v.pb(s);
    }
    int k;
    cin >> k;
    map<string,pair<ll,ll> >mp;
    map<string,string>mp2;
    int ff = 0;//,f2 = 0;
    f(k){
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        mp2[s1] = s2;
        if(!mp.count(s1)){
            mp[s1] = {0,0};
        }
        if(s3[0]=='i'){
            mp[s1].F++;
            //f2++;
        }
        else{
            mp[s1].F++,mp[s1].S++;
        }
    }
    for(auto i:v){
        if(mp[i].F>1){
            ff = 1;
        }
    }
    if(!ff){
        int f2 = 0;
        for(auto i:v){
            cout<<mp2[i]<<' ';
            if(!mp[i].S){
                f2 = 1;
            }
        }
        cout << endl;
        if(f2){
            cout<<"incorrect"<<endl;
        }
        else{
            cout<<"correct"<<endl;
        }
    }
    else{
        ll cor = 1;
        ll tot = 1;
        for(auto i:v){
            cor *= mp[i].S;
            tot *= mp[i].F;
        }
        ll inc = tot - cor;
        cout << cor <<' '<<"correct"<<endl;
        cout << inc <<' '<<"incorrect"<<endl;
    }
}
