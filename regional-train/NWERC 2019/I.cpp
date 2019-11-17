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
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i:v){
        cin >> i;
    }
    vector<int>tmp = v;
    sort(tmp.begin(),tmp.end());
    int f = 0;
    for(int i=0;i<n;i++){
        if(v[i]!=tmp[i]){
            f = 1;
        }
    }
    if(!f){
        cout << 1<<' '<<1<<endl;
        exit(0);
    }
    int st,ed;
    for(int i=0;i<n;i++){
        if(v[i]!=tmp[i]){
            st = i;
            ed = i+1;
            while(ed < n-1 && v[ed] >= v[ed+1]){
                ed++;
            }
            break;
        }
    }
    reverse(v.begin()+st,v.begin()+ed+1);
    f = 0;
    f(n){
        if(v[i]!=tmp[i]){
            f = 1;
        }
    }
    if(f){
        cout << "impossible" << endl;
    }
    else{
        cout << st + 1 << ' ' << ed+1 << endl;
    }
}
